# $Id: final.mk,v 1.3 2024/07/15 09:10:09 jperkin Exp $

.if !target(__${.PARSEFILE}__)
__${.PARSEFILE}__: .NOTMAIN

# provide a hook for folk who want to do scary stuff
.-include <${.CURDIR:H}/Makefile-final.inc>

.-include <local.final.mk>

.if ${MK_STAGING} == "yes"
.include <meta.stage.mk>
.elif !empty(STAGE)
.-include <stage.mk>
.endif

.if empty(_SKIP_BUILD)
install: realinstall
.endif
realinstall:

.endif
