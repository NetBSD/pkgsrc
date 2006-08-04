# $NetBSD: locking.mk,v 1.2 2006/08/04 20:52:27 rillig Exp $
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

_WRKDIR_LOCKFILE=	${WRKDIR}/.lockfile
_LOCALBASE_LOCKFILE=	${LOCALBASE}/.lockfile

#
# Sanity checks.
#

.if ${PKGSRC_LOCKTYPE} == "none"
# No further checks.
.elif ${PKGSRC_LOCKTYPE} == "once" || ${PKGSRC_LOCKTYPE} == "sleep"
.  if !defined(OBJHOSTNAME)
PKG_FAIL_REASON+=	"[locking.mk] PKGSRC_LOCKTYPE needs OBJHOSTNAME defined."
.  endif
.else
PKG_FAIL_REASON+=	"[locking.mk] PKGSRC_LOCKTYPE must be one of {none,once,sleep}, not ${PKGSRC_LOCKTYPE}."
.endif

#
# Needed tools.
#

.if ${PKGSRC_LOCKTYPE} != "none"
USE_TOOLS+=		shlock
.endif
.if ${PKGSRC_LOCKTYPE} == "sleep"
USE_TOOLS+=		sleep
.endif

#
# The commands.
#

_CHECK_IF_SHLOCK_IS_AVAILABLE_CMD= \
	${TEST} -x ${SHLOCK:Q}"" || {					\
		${ERROR_MSG} "[locking.mk] shlock is not installed.";	\
		${ERROR_MSG} "[locking.mk] Please \"cd ../../pkgtools/shlock && ${MAKE} install\"."; \
		exit 1;							\
	}

_ACQUIRE_LOCK_CMD= \
	${_CHECK_IF_SHLOCK_IS_AVAILABLE_CMD};				\
	ppid=`${PS} -p $$$$ -o ppid | ${AWK} 'NR == 2 { print $$1 }'`;	\
	if ${TEST} -z "$$ppid"; then					\
		${ERROR_MSG} "No parent process ID found.";		\
		exit 1;							\
	fi;								\
	while ${TRUE}; do						\
		if ${TEST} -f /var/run/dmesg.boot -a -f "$$lockfile"; then \
			rebooted=`${FIND} /var/run/dmesg.boot -newer "$$lockfile" -print`; \
			if ${TEST} -n "$$rebooted"; then		\
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
		case ${PKGSRC_LOCKTYPE:Q}"" in				\
		once)	${ERROR_MSG} "Lock is held by pid $$lockpid";	\
			exit 1;						\
			;;						\
		sleep)	${STEP_MSG} "Lock is held by pid $$lockpid";	\
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

.if ${PKGSRC_LOCKTYPE} == "none"
acquire-lock release-lock acquire-localbase-lock release-localbase-lock: .USE
	@${DO_NADA}
.else
acquire-lock: .USE
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	lockfile=${_WRKDIR_LOCKFILE};					\
	${_ACQUIRE_LOCK_CMD}

release-lock: .USE
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	lockfile=${_WRKDIR_LOCKFILE};					\
	${_RELEASE_LOCK_CMD}

acquire-localbase-lock: .USE
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	lockfile=${_LOCALBASE_LOCKFILE};				\
	${_ACQUIRE_LOCK_CMD}

release-localbase-lock: .USE
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	lockfile=${_LOCALBASE_LOCKFILE};				\
	${_RELEASE_LOCK_CMD}
.endif
