# $NetBSD: hacks.mk,v 1.2 2008/02/08 10:34:20 tnn Exp $

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly" && !empty(PKGSRC_COMPILER:Mgcc)
#
# The standalone modules doesn't support propolice.
#
.if !defined(HAS_PROPOLICE)
HAS_PROPOLICE!=	( ${CC} -v 2>&1 | ${GREP} 'propolice' ) 2>/dev/null || echo no
MAKEVARS+=	HAS_PROPOLICE
.endif

.if ${HAS_PROPOLICE} != "no"
CFLAGS+=	-fno-stack-protector
CXXFLAGS+=	-fno-stack-protector
.endif
.endif
