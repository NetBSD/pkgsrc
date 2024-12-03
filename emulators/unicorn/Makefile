# $NetBSD: Makefile,v 1.22 2024/12/03 11:51:00 jperkin Exp $

.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	CPU emulator engine framework based on QEMU
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS.SunOS+=	-DCMAKE_AR=${PREFIX}/gnu/bin/ar

.include "../../devel/cmake/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
