# $NetBSD: Makefile,v 1.25 2012/10/02 17:10:46 tron Exp $

DISTNAME=	geany-0.20
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	http://download.geany.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.geany.org/
COMMENT=	Geany integrated development environment (IDE)
#LICENSE=	gnu-gpl-v2 (or later) AND internal scintilla License.

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config msgfmt gmake perl:run intltool
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	geany.pc.in

CONFIGURE_ARGS+=	--enable-plugins
CONFIGURE_ARGS+=	--enable-vte
CONFIGURE_ARGS+=	--enable-socket

MAKE_FLAGS+=		CCLD=${CXX:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && !empty(PKGSRC_COMPILER:Msunpro)
CONFIGURE_ARGS+=	CC=sunpro
BUILDLINK_TRANSFORM+=	rm:-lstdc++
.endif

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
