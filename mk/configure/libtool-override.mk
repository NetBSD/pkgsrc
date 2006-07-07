# $NetBSD: libtool-override.mk,v 1.4 2006/07/07 15:25:05 jlam Exp $

######################################################################
### {ltconfig,libtool,shlibtool}-override (PRIVATE)
######################################################################
### {ltconfig,libtool,shlibtool}-override replace any existing ltconfig
### and libtool under ${WRKSRC} with the versions installed by pkgsrc.
###
.if defined(LTCONFIG_OVERRIDE)
do-configure-pre-hook: ltconfig-override
.endif
do-configure-post-hook: libtool-override
.if defined(SHLIBTOOL_OVERRIDE)
do-configure-post-hook: shlibtool-override
.endif

OVERRIDE_DIRDEPTH.ltconfig?=	${OVERRIDE_DIRDEPTH}
OVERRIDE_DIRDEPTH.libtool?=	${OVERRIDE_DIRDEPTH}
OVERRIDE_DIRDEPTH.shlibtool?=	${OVERRIDE_DIRDEPTH}

_SCRIPT.ltconfig-override=						\
	${RM} -f $$file;						\
	${ECHO} "${RM} -f libtool; ${LN} -s ${_LIBTOOL} libtool" > $$file; \
	${CHMOD} +x $$file

.PHONY: ltconfig-override
ltconfig-override:
	@${STEP_MSG} "Modifying ltconfig scripts to use pkgsrc libtool"
.if defined(LTCONFIG_OVERRIDE) && !empty(LTCONFIG_OVERRIDE)
	${_PKG_SILENT}${_PKG_DEBUG}set -e;				\
	cd ${WRKSRC};							\
	for file in ${LTCONFIG_OVERRIDE}; do				\
		${TEST} -f "$$file" || continue;			\
		${_SCRIPT.${.TARGET}};					\
	done
.else
	${_PKG_SILENT}${_PKG_DEBUG}set -e;				\
	cd ${WRKSRC};							\
	depth=0; pattern=ltconfig;					\
	while ${TEST} $$depth -le ${OVERRIDE_DIRDEPTH.ltconfig}; do	\
		for file in $$pattern; do				\
			${TEST} -f "$$file" || continue;		\
			${_SCRIPT.${.TARGET}};				\
		done;							\
		depth=`${EXPR} $$depth + 1`; pattern="*/$$pattern";	\
	done
.endif

_OVERRIDE_PATH.libtool=		${_LIBTOOL}
_OVERRIDE_PATH.shlibtool=	${_SHLIBTOOL}

.for _script_ in libtool shlibtool
_SCRIPT.${_script_}-override=						\
	${RM} -f $$file;						\
	${ECHO} "\#!"${TOOLS_SH:Q} > $$file;				\
	${ECHO} "exec" ${_OVERRIDE_PATH.${_script_}:Q} '"$$@"' >> $$file; \
	${CHMOD} +x $$file
.endfor

.PHONY: libtool-override
libtool-override:
	@${STEP_MSG} "Modifying libtool scripts to use pkgsrc libtool"
.if defined(LIBTOOL_OVERRIDE)
	${_PKG_SILENT}${_PKG_DEBUG}set -e;				\
	cd ${WRKSRC};							\
	for file in ${LIBTOOL_OVERRIDE}; do				\
		${TEST} -f "$$file" || continue;			\
		${_SCRIPT.${.TARGET}};					\
	done
.else
	${_PKG_SILENT}${_PKG_DEBUG}set -e;				\
	cd ${WRKSRC};							\
	depth=0; pattern=libtool;					\
	while ${TEST} $$depth -le ${OVERRIDE_DIRDEPTH.libtool}; do	\
		for file in $$pattern; do				\
			${TEST} -f "$$file" || continue;		\
			${_SCRIPT.${.TARGET}};				\
		done;							\
		depth=`${EXPR} $$depth + 1`; pattern="*/$$pattern";	\
	done
.endif

.PHONY: shlibtool-override
shlibtool-override:
	@${STEP_MSG} "Modifying libtool scripts to use pkgsrc shlibtool"
.if defined(SHLIBTOOL_OVERRIDE) && !empty(SHLIBTOOL_OVERRIDE)
	${_PKG_SILENT}${_PKG_DEBUG}set -e;				\
	cd ${WRKSRC};							\
	for file in ${SHLIBTOOL_OVERRIDE}; do				\
		${TEST} -f "$$file" || continue;			\
		${_SCRIPT.${.TARGET}};					\
	done
.else
	${_PKG_SILENT}${_PKG_DEBUG}set -e;				\
	cd ${WRKSRC};							\
	depth=0; pattern=libtool;					\
	while ${TEST} $$depth -le ${OVERRIDE_DIRDEPTH.shlibtool}; do	\
		for file in $$pattern; do				\
			${TEST} -f "$$file" || continue;		\
			${_SCRIPT.${.TARGET}};				\
		done;							\
		depth=`${EXPR} $$depth + 1`; pattern="*/$$pattern";	\
	done
.endif
