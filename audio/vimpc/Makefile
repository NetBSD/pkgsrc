# $NetBSD: Makefile,v 1.7 2021/04/21 13:24:23 adam Exp $

DISTNAME=	vimpc-0.09.2
PKGREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=boysetsfrog/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/boysetsfrog/vimpc
COMMENT=	Client for musicpd with vi-like key bindings
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoreconf autoconf automake
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++11

# C++11
GCC_REQD+=	4.7

USE_CURSES=	wide getmouse

CONFIGURE_ARGS+=	--enable-boost=no

pre-configure:
	cd ${WRKSRC} && autoreconf --force --install

.include "../../audio/libmpdclient/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
