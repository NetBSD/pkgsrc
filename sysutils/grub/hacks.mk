# $NetBSD: hacks.mk,v 1.1 2006/05/09 18:52:35 joerg Exp $

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly" && ${PKGSRC_COMPILER} == "gcc"
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
