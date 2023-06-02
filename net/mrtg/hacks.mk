# $NetBSD: hacks.mk,v 1.2 2023/06/02 14:23:58 wiz Exp $

.if !defined(MRTG_HACKS_MK)
MRTG_HACKS_MK=	defined

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/compiler.mk"

# http://gcc.gnu.org/bugzilla/show_bug.cgi?id=48830
# PR port-sparc64/46719
.if !empty(PKGSRC_COMPILER:Mgcc) && ${CC_VERSION:Mgcc-4.[0-6]*} && ${MACHINE_PLATFORM:M*-*-sparc64}
CFLAGS+=	-O1
.endif

.endif	# MRTG_HACKS_MK
