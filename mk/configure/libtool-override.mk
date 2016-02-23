# $NetBSD: libtool-override.mk,v 1.12 2016/02/23 15:19:23 joerg Exp $

######################################################################
### {libtool,shlibtool,depcomp}-override (PRIVATE)
######################################################################
### {libtool,shlibtool,depcomp}-override replace any existing libtool under
### ${WRKSRC} with the version installed by pkgsrc.
### depcomp-override replaces the depcomp tool with the canonical version.
###
do-configure-post-hook: libtool-override depcomp-override
.if defined(SHLIBTOOL_OVERRIDE)
do-configure-post-hook: shlibtool-override
.endif

OVERRIDE_DIRDEPTH.libtool?=	${OVERRIDE_DIRDEPTH}
OVERRIDE_DIRDEPTH.shlibtool?=	${OVERRIDE_DIRDEPTH}
OVERRIDE_DIRDEPTH.depcomp?=	${OVERRIDE_DIRDEPTH}

_OVERRIDE_PATH.libtool=		${LIBTOOL}
_OVERRIDE_PATH.shlibtool=	${SHLIBTOOL}
_OVERRIDE_PATH.depcomp=		${LOCALBASE}/share/libtool/config/depcomp

.for _script_ in libtool shlibtool depcomp
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
	${RUN} \
	cd ${WRKSRC};							\
	set -- dummy ${LIBTOOL_OVERRIDE}; shift;			\
	while [ $$# -gt 0 ]; do						\
		file="$$1"; shift;					\
		[ -f "$$file" ] || [ -h "$$file" ] || continue;		\
		${_SCRIPT.${.TARGET}};					\
	done
.else
	${RUN} \
	cd ${WRKSRC};							\
	depth=0; pattern=libtool;					\
	while [ $$depth -le ${OVERRIDE_DIRDEPTH.libtool} ]; do		\
		for file in $$pattern; do				\
			[ -f "$$file" ] || [ -h "$$file" ] || continue; \
			${_SCRIPT.${.TARGET}};				\
		done;							\
		depth=`${EXPR} $$depth + 1`; pattern="*/$$pattern";	\
	done
.endif

.PHONY: shlibtool-override
shlibtool-override:
	@${STEP_MSG} "Modifying libtool scripts to use pkgsrc shlibtool"
.if defined(SHLIBTOOL_OVERRIDE) && !empty(SHLIBTOOL_OVERRIDE)
	${RUN} \
	cd ${WRKSRC};							\
	set -- dummy ${SHLIBTOOL_OVERRIDE}; shift;			\
	while [ $$# -gt 0 ]; do						\
		file="$$1"; shift;					\
		[ -f "$$file" ] || [ -h "$$file" ] || continue;		\
		${_SCRIPT.${.TARGET}};					\
	done
.else
	${RUN} \
	cd ${WRKSRC};							\
	depth=0; pattern=libtool;					\
	while [ $$depth -le ${OVERRIDE_DIRDEPTH.shlibtool} ]; do	\
		for file in $$pattern; do				\
			[ -f "$$file" ] || [ -h "$$file" ] || continue; \
			${_SCRIPT.${.TARGET}};				\
		done;							\
		depth=`${EXPR} $$depth + 1`; pattern="*/$$pattern";	\
	done
.endif

.PHONY: depcomp-override
depcomp-override:
	@${STEP_MSG} "Modifying libtool scripts to use pkgsrc depcomp"
.if !empty(DEPCOMP_OVERRIDE:U)
	${RUN} \
	cd ${WRKSRC};							\
	set -- dummy ${DEPCOMP_OVERRIDE}; shift;			\
	while [ $$# -gt 0 ]; do						\
		file="$$1"; shift;					\
		[ -f "$$file" ] || [ -h "$$file" ] || continue;		\
		${_SCRIPT.${.TARGET}};					\
	done
.else
	${RUN} \
	cd ${WRKSRC};							\
	depth=0; pattern=depcomp;					\
	while [ $$depth -le ${OVERRIDE_DIRDEPTH.depcomp} ]; do	\
		for file in $$pattern; do				\
			[ -f "$$file" ] || [ -h "$$file" ] || continue; \
			${_SCRIPT.${.TARGET}};				\
		done;							\
		depth=`${EXPR} $$depth + 1`; pattern="*/$$pattern";	\
	done
.endif
