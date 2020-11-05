# $NetBSD: Makefile,v 1.69 2020/11/05 00:54:04 gutteridge Exp $

DISTNAME=	geany-1.37
CATEGORIES=	devel
MASTER_SITES=	http://download.geany.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.geany.org/
COMMENT=	Geany integrated development environment (IDE)
LICENSE=	gnu-gpl-v2 # AND internal Scintilla License.

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config msgfmt gmake perl:run intltool
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	geany.pc.in

CONFIGURE_ARGS+=	--enable-plugins
CONFIGURE_ARGS+=	--enable-vte
CONFIGURE_ARGS+=	--enable-socket
CONFIGURE_ARGS+=	--disable-gtkdoc-header

MAKE_FLAGS+=		CCLD=${CXX:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && !empty(PKGSRC_COMPILER:Msunpro)
CONFIGURE_ARGS+=	CC=sunpro
BUILDLINK_TRANSFORM+=	rm:-lstdc++
.endif

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
