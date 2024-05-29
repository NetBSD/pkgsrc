# $NetBSD: Makefile,v 1.8 2024/05/29 16:33:57 adam Exp $

DISTNAME=	libnpupnp-4.1.5
PKGREVISION=	7
CATEGORIES=	net
MASTER_SITES=	https://www.lesbonscomptes.com/upmpdcli/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.lesbonscomptes.com/upmpdcli/pages/downloads.html
COMMENT=	C++ reimplementation of the libupnp
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libnpupnp.pc.in

.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
