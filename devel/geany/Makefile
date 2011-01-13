# $NetBSD: Makefile,v 1.17 2011/01/13 13:37:22 wiz Exp $

DISTNAME=	geany-0.17
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=geany/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://geany.uvena.de/
COMMENT=	Geany integrated development environment (IDE)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config msgfmt gmake perl:run intltool
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--enable-plugins
CONFIGURE_ARGS+=	--enable-vte
CONFIGURE_ARGS+=	--enable-socket

MAKE_FLAGS+=		CCLD=${CXX:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && !empty(PKGSRC_COMPILER:Msunpro)
CONFIGURE_ARGS+=	CC=sunpro
BUILDLINK_TRANSFORM+=	rm:-lstdc++
.else
CONFIGURE_ARGS+=	CC=gcc
.endif

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
