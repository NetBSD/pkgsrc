# $NetBSD: utility.mk,v 1.10 2008/02/18 14:30:40 obache Exp $

# The 'info' target can be used to display information about a package.
.PHONY: info
info:
	${_PKG_SILENT}${_PKG_DEBUG}${PKG_INFO} "${PKGWILDCARD}"

# The 'check' target can be used to check an installed package.
.PHONY: check
check:
	${_PKG_SILENT}${_PKG_DEBUG}${PKG_ADMIN} check "${PKGWILDCARD}"

# The 'list' target can be used to list the files installed by a package.
.PHONY: list
list:
	${_PKG_SILENT}${_PKG_DEBUG}${PKG_INFO} -L "${PKGWILDCARD}"

######################################################################
###
### The targets below should probably be removed from pkgsrc.
###
######################################################################

# show-downlevel:
#	Lists the packages whose installed version does not match the
#	current version in pkgsrc.
#
show-downlevel: .PHONY
.if defined(PKG_FAIL_REASON)
	${_PKG_SILENT}${_PKG_DEBUG}${DO_NADA}
.else
	${_PKG_SILENT}${_PKG_DEBUG}					\
	found="`${_PKG_BEST_EXISTS} \"${PKGWILDCARD}\" || ${TRUE}`";	\
	if [ "X$$found" != "X" -a "X$$found" != "X${PKGNAME}" ]; then	\
		${ECHO} "${PKGBASE} package: $$found installed, pkgsrc version ${PKGNAME}"; \
		if [ "X$$STOP_DOWNLEVEL_AFTER_FIRST" != "X" ]; then	\
			${ECHO} "stopping after first downlevel pkg found"; \
			exit 1;						\
		fi;							\
	fi
.endif

.PHONY: show-installed-depends
show-installed-depends: # will not be removed
.if !empty(DEPENDS)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for i in ${DEPENDS:C/:.*$//:Q:S/\ / /g} ; do			\
		echo "$$i =>" `${_PKG_BEST_EXISTS} "$$i"`;		\
	done
.endif

.PHONY: show-needs-update
show-needs-update: _about-to-be-removed
.if !empty(DEPENDS)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${_DEPENDS_WALK_CMD} -r ${PKGPATH} |				\
	while read i; do						\
		cd ${PKGSRCDIR}/$$i;					\
		eval `${RECURSIVE_MAKE} ${MAKEFLAGS} show-vars-eval VARS='PKGNAME:want PKGWILDCARD:wild'`; \
		have=`${_PKG_BEST_EXISTS} "$$wild" || ${TRUE}`;		\
		if [ -z "$$have" ]; then				\
			${ECHO} "$$i => (none) => needs install of $$want"; \
		elif [ "$$have" != "$$want" ]; then			\
			${ECHO} "$$i => $$have => needs update to $$want"; \
		fi;							\
	done
.endif

.PHONY: show-pkgsrc-dir
show-pkgsrc-dir: _about-to-be-removed
.if defined(PKG_FAIL_REASON)
	${_PKG_SILENT}${_PKG_DEBUG}${DO_NADA}
.else
	${_PKG_SILENT}${_PKG_DEBUG}					\
	found="`${_PKG_BEST_EXISTS} \"${PKGWILDCARD}\" || ${TRUE}`";	\
	if [ "X$$found" != "X" ]; then					\
		${ECHO} ${PKGPATH};					\
	fi
.endif

.PHONY: show-depends-options
show-depends-options:
	${RUN}                                                          \
	${_DEPENDS_WALK_CMD} ${PKGPATH} |                               \
	while read dir; do                                              \
		${ECHO} "===> Options for $${dir}" &&                   \
		cd ${.CURDIR}/../../$$dir &&                            \
		${RECURSIVE_MAKE} ${MAKEFLAGS} show-options;            \
	done

# Short aliases
.PHONY: sid
sid: show-installed-depends

_about-to-be-removed: .USE
	@${WARNING_MSG} "This make target (${.TARGET}) is about to be removed. Since you used"
	@${WARNING_MSG} "it, it may not be completele useless.  Please tell us on the"
	@${WARNING_MSG} "tech-pkg""@""NetBSD.org mailing list why you think this target should"
	@${WARNING_MSG} "not be removed."
