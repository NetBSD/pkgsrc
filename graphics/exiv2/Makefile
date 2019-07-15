# $NetBSD: Makefile,v 1.41 2019/07/15 22:07:08 nia Exp $

VER=		0.27.1
DISTNAME=	exiv2-${VER}-Source
PKGNAME=	${DISTNAME:S/-Source//}
CATEGORIES=	graphics
MASTER_SITES=	https://www.exiv2.org/builds/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.exiv2.org/
COMMENT=	Image metadata manipulation
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	msgfmt
USE_LANGUAGES=	c c++
GCC_REQD+=	3.3

CMAKE_ARGS+=	-DEXIV2_BUILD_SAMPLES:BOOL=OFF

LDFLAGS.Linux+=	-ldl
LDFLAGS.SunOS+=	-lsocket -lnsl

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE=	config/exiv2.pc.in

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
