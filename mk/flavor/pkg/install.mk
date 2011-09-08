# $NetBSD: install.mk,v 1.15 2011/09/08 20:17:16 abs Exp $
#
# _flavor-check-conflicts:
#	Checks for conflicts between the package and installed packages.
#
#	XXX: Needs WRKDIR.
#
# _flavor-check-installed:
#	Checks if the package (or an older version of it) is already
#	installed on the system.
#
#	XXX: Needs WRKDIR.
#
# _flavor-register:
#	Populates the package database with the appropriate entries to
#	register the package as being installed on the system.
#
# _flavor-install-clean:
#	Removes the state files from the run of an ``install'' target.
#

_flavor-check-conflicts: .PHONY error-check
	${RUN}${RM} -f ${WRKDIR}/.CONFLICTS
.for _conflict_ in ${CONFLICTS}
	${RUN}								\
	found="`${_PKG_BEST_EXISTS} ${_conflict_:Q} || ${TRUE}`";	\
	case "$$found" in						\
	"")	;;							\
	*)	${ECHO} "$$found" >> ${WRKDIR}/.CONFLICTS ;;		\
	esac
.endfor
	${RUN}								\
	${TEST} -f ${WRKDIR}/.CONFLICTS || exit 0;			\
	exec 1>${ERROR_DIR}/${.TARGET};					\
	${ECHO} "${PKGNAME} conflicts with installed package(s):";	\
	${CAT} ${WRKDIR}/.CONFLICTS | ${SED} -e "s|^|    |";		\
	${ECHO} "They install the same files into the same place.";	\
	${ECHO} "Please remove conflicts first with pkg_delete(1).";	\
	${RM} -f ${WRKDIR}/.CONFLICTS

_flavor-check-installed: .PHONY error-check
	${RUN}								\
	found="`${_PKG_BEST_EXISTS} ${PKGWILDCARD:Q} || ${TRUE}`";	\
	${TEST} -n "$$found" || exit 0;					\
	exec 1>${ERROR_DIR}/${.TARGET};					\
	${ECHO} "$$found is already installed - perhaps an older version?"; \
	${ECHO} "If so, you may use either of:";			\
	${ECHO} "    - \"pkg_delete $$found\" and \"${MAKE} reinstall\""; \
	${ECHO} "      to upgrade properly";				\
	${ECHO} "    - \"${MAKE} update\" to rebuild the package and all"; \
	${ECHO} "      of its dependencies";				\
	${ECHO} "    - \"${MAKE} replace\" to replace only the package without"; \
	${ECHO} "      re-linking dependencies, risking various problems."

_REGISTER_DEPENDENCIES=							\
	${PKGSRC_SETENV} PKG_DBDIR=${_PKG_DBDIR:Q}				\
		AWK=${TOOLS_AWK:Q}					\
	${SH} ${PKGSRCDIR}/mk/flavor/pkg/register-dependencies

_flavor-register: .PHONY _flavor-generate-metadata ${_RDEPENDS_FILE}
	@${STEP_MSG} "Registering installation for ${PKGNAME}"
	${RUN}${RM} -fr ${_PKG_DBDIR}/${PKGNAME}
	${RUN}${MKDIR} ${_PKG_DBDIR}/${PKGNAME}
	${RUN}${CP} ${PKG_DB_TMPDIR}/* ${_PKG_DBDIR}/${PKGNAME}
	${RUN}${PKG_ADMIN} add ${PKGNAME}
	${RUN}								\
	case ${_AUTOMATIC:Q}"" in					\
	[yY][eE][sS])	${PKG_ADMIN} set automatic=yes ${PKGNAME} ;;	\
	esac
	${RUN}${_FULL_DEPENDS_CMD} |					\
		${SORT} -u | ${_REGISTER_DEPENDENCIES} ${PKGNAME}
	${RUN}${GREP} '^@pkgdir ' < ${_PKG_DBDIR}/${PKGNAME}/+CONTENTS | \
	    while read tag dir; do ${MKDIR} ${PREFIX}/$$dir; done

_flavor-install-clean: .PHONY _flavor-clean-metadata
