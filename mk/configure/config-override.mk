# $NetBSD: config-override.mk,v 1.7 2013/10/13 10:10:05 wiz Exp $

######################################################################
### config-{guess,sub}-override (PRIVATE)
######################################################################
### config-{guess,sub}-override replace any existing config.guess and
### config.sub under ${WRKSRC} with the specially-kept versions
### under pkgsrc/mk/gnu-config.
###
do-configure-pre-hook: config-guess-override
do-configure-pre-hook: config-sub-override

_OVERRIDE_VAR.guess=	CONFIG_GUESS_OVERRIDE
_OVERRIDE_VAR.sub=	CONFIG_SUB_OVERRIDE

OVERRIDE_DIRDEPTH.config-guess?=	${OVERRIDE_DIRDEPTH}
OVERRIDE_DIRDEPTH.config-sub?=		${OVERRIDE_DIRDEPTH}

.for _sub_ in guess sub
_SCRIPT.config-${_sub_}-override=					\
	${RM} -f $$file;						\
	${LN} -fs ${PKGSRCDIR}/mk/gnu-config/config.${_sub_} $$file

.PHONY: config-${_sub_}-override
config-${_sub_}-override:
	@${STEP_MSG} "Replacing config-${_sub_} with pkgsrc versions"
.  if defined(${_OVERRIDE_VAR.${_sub_}}) && !empty(${_OVERRIDE_VAR.${_sub_}})
	${RUN} \
	cd ${WRKSRC};							\
	for file in ${${_OVERRIDE_VAR.${_sub_}}}; do			\
		[ -f "$$file" ] || [ -h "$$file" ] || continue;		\
		${_SCRIPT.${.TARGET}};					\
	done
.  else
	${RUN} \
	cd ${WRKSRC};							\
	depth=0; pattern=config.${_sub_};				\
	while [ $$depth -le ${OVERRIDE_DIRDEPTH.config-${_sub_}} ]; do	\
		for file in $$pattern; do				\
			[ -f "$$file" ] || [ -h "$$file" ] || continue;	\
			${_SCRIPT.${.TARGET}};				\
		done;							\
		depth=`${EXPR} $$depth + 1`; pattern="*/$$pattern";	\
	done
.  endif
.endfor
