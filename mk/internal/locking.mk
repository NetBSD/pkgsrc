# $NetBSD: locking.mk,v 1.9 2007/03/16 20:41:44 rillig Exp $
#
# User-settable variables:
#
# WRKDIR_LOCKTYPE
#	The type of locking used for WRKDIR.
#
#	Possible values: none once sleep
#	Default value: none
#	Recommended: once
#
# LOCALBASE_LOCKTYPE
#	The type of locking used for LOCALBASE.
#
#	Possible values: none once sleep
#	Default value: none
#	Recommended: sleep
#
# See also: PKGSRC_LOCKTYPE.
#

# This file provides the following .USE targets:
#
# acquire-lock
#	Acquires a coarse-grained lock in WRKDIR.
#
# release-lock
#	Releases the lock in WRKDIR.
#
# acquire-localbase-lock
#	Acquires a coarse-grained lock in LOCALBASE.
#
# release-localbase-lock
#	Releases the lock in LOCALBASE.
#

WRKDIR_LOCKTYPE?=	${PKGSRC_LOCKTYPE}
LOCALBASE_LOCKTYPE?=	${PKGSRC_LOCKTYPE}

_WRKDIR_LOCKFILE=	${WRKDIR}/.lockfile
_LOCALBASE_LOCKFILE=	${LOCALBASE}/.lockfile
_LOCKVARS=		WRKDIR_LOCKTYPE LOCALBASE_LOCKTYPE

#
# Sanity checks.
#

.for v in ${_LOCKVARS}
_OK=	no
.  for t in none once sleep
.    if ${${v}} == "${t}"
_OK=	yes
.    endif
.  endfor
.  if ${_OK} != "yes"
PKG_FAIL_REASON+=	"[locking.mk] ${v} must be one of { none once sleep }, not ${${v}}."
.  endif
.endfor

#
# Needed tools.
#

.for v in ${_LOCKVARS}
.  if ${${v}} != "none"
USE_TOOLS+=		shlock
.  endif
.  if ${${v}} == "sleep"
USE_TOOLS+=		sleep
.  endif
.endfor

#
# The commands.
#

_CHECK_IF_SHLOCK_IS_AVAILABLE_CMD= \
	[ "${PKGPATH}" != "pkgtools/shlock" ] || exit 0;		\
	[ -x ${SHLOCK:Q}"" ] || {					\
		${ERROR_MSG} "[locking.mk] shlock is not installed.";	\
		${ERROR_MSG} "[locking.mk] Please \"(cd ../../pkgtools/shlock && ${MAKE} install)\"."; \
		exit 1;							\
	}

_ACQUIRE_LOCK_CMD= \
	${_CHECK_IF_SHLOCK_IS_AVAILABLE_CMD};				\
	ppid=`${PS} -p $$$$ -o ppid | ${AWK} 'NR == 2 { print $$1 }'`;	\
	if [ -z "$$ppid" ]; then					\
		${ERROR_MSG} "No parent process ID found.";		\
		exit 1;							\
	fi;								\
	while :; do							\
		if [ -f /var/run/dmesg.boot -a -f "$$lockfile" ]; then	\
			rebooted=`${FIND} /var/run/dmesg.boot -newer "$$lockfile" -print`; \
			if [ "$$rebooted" ]; then			\
				${STEP_MSG} "Removing stale $$lockfile"; \
				${RM} -f "$$lockfile";			\
			fi;						\
		fi;							\
		lockdir=`echo "$$lockfile" | sed "s,/[^/]*\$$,,"`;	\
		${MKDIR} "$$lockdir";					\
		if ${SHLOCK} -f "$$lockfile" -p "$$ppid"; then		\
			break;						\
		fi;							\
		lockpid=`${CAT} "$$lockfile"`;				\
		case "$$locktype" in					\
		once)	${FAIL_MSG} "Lock ${.TARGET} is held by pid $$lockpid" ;; \
		sleep)	${STEP_MSG} "Lock ${.TARGET} is held by pid $$lockpid";	\
			${SLEEP} ${PKGSRC_SLEEPSECS};			\
			;;						\
		esac;							\
	done;
.if defined(PKG_VERBOSE)
_ACQUIRE_LOCK_CMD+= \
	lockpid=`${CAT} "$$lockfile"`;					\
	${STEP_MSG} "Lock $$lockfile acquired for \`\`${.TARGET:S/^acquire-//:S/-lock$//}'' on behalf of process $$lockpid";
.endif

_RELEASE_LOCK_CMD=	# nothing
.if defined(PKG_VERBOSE)
_RELEASE_LOCK_CMD+= \
	lockpid=`${CAT} "$$lockfile"`;				\
	${STEP_MSG} "Lock $$lockfile released for \`\`${.TARGET:S/^release-//:S/-lock$//}'' on behalf of process $$lockpid";
.endif
_RELEASE_LOCK_CMD+= \
	${RM} -f "$$lockfile"

#
# The targets.
#

.PHONY: acquire-lock release-lock
.PHONY: acquire-localbase-lock release-localbase-lock

.if ${LOCALBASE_LOCKTYPE} == "none"
acquire-localbase-lock release-localbase-lock: .USE
	@${DO_NADA}
.else
acquire-localbase-lock: .USE
	${RUN}								\
	lockfile=${_LOCALBASE_LOCKFILE};				\
	locktype=${LOCALBASE_LOCKTYPE};					\
	${_ACQUIRE_LOCK_CMD}

release-localbase-lock: .USE
	${RUN}								\
	lockfile=${_LOCALBASE_LOCKFILE};				\
	locktype=${LOCALBASE_LOCKTYPE};					\
	${_RELEASE_LOCK_CMD}
.endif

.if ${WRKDIR_LOCKTYPE} == "none"
acquire-lock release-lock: .USE
	@${DO_NADA}
.else
acquire-lock: .USE
	${RUN}								\
	lockfile=${_WRKDIR_LOCKFILE};					\
	locktype=${WRKDIR_LOCKTYPE};					\
	${_ACQUIRE_LOCK_CMD}

release-lock: .USE
	${RUN}								\
	lockfile=${_WRKDIR_LOCKFILE};					\
	locktype=${WRKDIR_LOCKTYPE};					\
	${_RELEASE_LOCK_CMD}

.endif
