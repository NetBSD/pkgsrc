# $NetBSD: libtool-override.mk,v 1.5 2006/07/19 19:14:39 jlam Exp $

######################################################################
### {libtool,shlibtool}-override (PRIVATE)
######################################################################
### {libtool,shlibtool}-override replace any existing libtool under
### ${WRKSRC} with the version installed by pkgsrc.
###
do-configure-post-hook: libtool-override
.if defined(SHLIBTOOL_OVERRIDE)
do-configure-post-hook: shlibtool-override
.endif

OVERRIDE_DIRDEPTH.libtool?=	${OVERRIDE_DIRDEPTH}
OVERRIDE_DIRDEPTH.shlibtool?=	${OVERRIDE_DIRDEPTH}

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
