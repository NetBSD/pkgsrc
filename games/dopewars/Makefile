# $NetBSD: Makefile,v 1.94 2024/05/29 16:32:33 adam Exp $

DISTNAME=	dopewars-1.6.2
PKGREVISION=	10
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dopewars/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dopewars.sourceforge.io/
COMMENT=	Make a fortune dealing drugs on the streets of New York
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	destdir

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-networking
CONFIGURE_ARGS+=	--without-esd
CONFIGURE_ARGS+=	--without-sdl
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/games

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
