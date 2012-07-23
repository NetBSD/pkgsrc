# $NetBSD: hacks.mk,v 1.1 2012/07/23 08:13:31 martin Exp $

.if !defined(MRTG_HACKS_MK)
MRTG_HACKS_MK=	defined

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/compiler.mk"

# http://gcc.gnu.org/bugzilla/show_bug.cgi?id=48830
# PR port-sparc64/46719
.if !empty(PKGSRC_COMPILER:Mgcc) && !empty(CC_VERSION:Mgcc-4.[0-6]*) && !empty(MACHINE_PLATFORM:M*-*-sparc64)
CFLAGS+=	-O1
.endif

.endif	# MRTG_HACKS_MK
