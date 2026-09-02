# $NetBSD: Makefile,v 1.24 2026/09/02 19:02:00 wiz Exp $

PKGREVISION= 2
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	CPU emulator engine framework based on QEMU
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS.SunOS+=	-DCMAKE_AR=${PREFIX}/gnu/bin/ar

.include "../../devel/cmake/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
