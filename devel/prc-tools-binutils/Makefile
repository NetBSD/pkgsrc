# $NetBSD: Makefile,v 1.6 2001/07/05 11:08:07 dillo Exp $
#

PKGNAME=	prc-tools-binutils-${PRC_TOOLS_VERS}
COMMENT=	binutils and host tools for GNU tool chain for Palm cross development

.include "../../mk/bsd.prefs.mk"

# optimized compile makes gcc segfault
.if (${MACHINE_ARCH} == "alpha")
CFLAGS+=-O0
.endif

BASE_DIST=	binutils
BASE_VERS=	2.9.1

.include "../../devel/prc-tools/Makefile.common"

USE_BUILDLINK_ONLY=	YES

.include "../../mk/bsd.pkg.mk"
