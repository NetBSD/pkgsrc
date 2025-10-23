# $NetBSD: Makefile,v 1.23 2025/10/23 20:36:53 wiz Exp $

PKGREVISION= 1
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	CPU emulator engine framework based on QEMU
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS.SunOS+=	-DCMAKE_AR=${PREFIX}/gnu/bin/ar

.include "../../devel/cmake/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
