# $NetBSD: Makefile,v 1.89 2024/05/29 16:32:44 adam Exp $

DISTNAME=		teg-0.12.0
PKGREVISION=		4
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GITHUB:=wfx/}

MAINTAINER=		wrzymski@gmail.com
HOMEPAGE=		https://github.com/wfx/teg
COMMENT=		Round-based computer board game (similar to Risk)
LICENSE=		gnu-gpl-v2

TOOL_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoconf automake autopoint autoreconf gmake pkg-config

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../devel/glib2/schemas.mk"
.include "../../graphics/goocanvas2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
