# $NetBSD: Makefile,v 1.11 2023/11/09 12:15:50 adam Exp $

DISTNAME=	spice-0.15.2
PKGNAME=	${DISTNAME:S/spice/spice-server/}
CATEGORIES=	sysutils
MASTER_SITES=	https://www.spice-space.org/download/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.spice-space.org/
COMMENT=	Simple Protocol for Independent Computing Environments
LICENSE=	gnu-lgpl-v2.1

USE_CXX_FEATURES=	c++11

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes
TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	spice-server.pc.in
PYTHON_FOR_BUILD_ONLY=	tool

LDFLAGS.SunOS+=	-lnsl -lsocket

.include "../../audio/libopus/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/spice-protocol/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
