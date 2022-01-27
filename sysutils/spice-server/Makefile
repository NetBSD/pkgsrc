# $NetBSD: Makefile,v 1.7 2022/01/27 19:04:12 wiz Exp $

DISTNAME=	spice-0.14.3
PKGNAME=	${DISTNAME:S/spice/spice-server/}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://www.spice-space.org/download/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.spice-space.org/
COMMENT=	Simple Protocol for Independent Computing Environments
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	spice-server.pc.in

LDFLAGS.SunOS+=	-lnsl -lsocket

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../audio/libopus/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/spice-protocol/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
