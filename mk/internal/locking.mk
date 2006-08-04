# $NetBSD: locking.mk,v 1.1 2006/08/04 05:55:18 rillig Exp $
#

# acquire-lock and release-lock are two .USE macro targets that aquire
# and release coarse-grained locks. There are two areas of pkgsrc that
# can be locked: The WRKDIR of a specific package or the LOCALBASE.
# Which of those is locked depends on the name of the target where the
# {acquire,release}-lock macro is used. If it contains -install-, as for
# example acquire-install-lock, LOCALBASE is locked. Otherwise, WRKDIR
# is locked.
#
# 

_WRKDIR_LOCKFILE=	${WRKDIR}/.lockfile
_PREFIX_LOCKFILE=	${PKG_DBDIR}/.lockfile
_GET_LOCKFILE_CMD= \
	case ${.TARGET} in						\
	*-install-*)	lockfile=${_PREFIX_LOCKFILE};;			\
	*)		lockfile=${_WRKDIR_LOCKFILE};;			\
	esac

acquire-lock: .USE
.if ${PKGSRC_LOCKTYPE} == "none"
	@${DO_NADA}
.else
	@if ${TEST} ! -x ${SHLOCK:Q}""; then				\
		${ERROR_MSG} "The ${SHLOCK:Q} utility does not exist, and is necessary for locking."; \
		${ERROR_MSG} "Please \""${MAKE:Q}" install\" in ../../pkgtools/shlock."; \
		exit 1;							\
	fi
.  if !defined(OBJHOSTNAME)
	@${ERROR_MSG} "PKGSRC_LOCKTYPE needs OBJHOSTNAME defined.";	\
	exit 1
.  endif
	${_PKG_SILENT}${_PKG_DEBUG}set -e;				\
	${_GET_LOCKFILE_CMD};						\
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
		if ${SHLOCK} -f "$$lockfile" -p $$ppid; then		\
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
	done;								\
	if ${PKG_VERBOSE:D${TRUE}:U${FALSE}}; then			\
		lockpid=`${CAT} "$$lockfile"`;				\
		${STEP_MSG} "Lock acquired for \`\`${.TARGET:S/^acquire-//:S/-lock$//}'' on behalf of process $$lockpid"; \
	fi
.endif

release-lock: .USE
.if ${PKGSRC_LOCKTYPE} == "none"
	@${DO_NADA}
.else
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	${_GET_LOCKFILE_CMD};						\
	if ${PKG_VERBOSE:D${TRUE}:U${FALSE}}; then			\
		lockpid=`${CAT} "$$lockfile"`;				\
		${STEP_MSG} "Lock released for \`\`${.TARGET:S/^release-//:S/-lock$//}'' on behalf of process $$lockpid"; \
	fi;								\
	${RM} -f "$$lockfile"
.endif
