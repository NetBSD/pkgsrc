# $NetBSD: Makefile,v 1.20 2020/11/05 09:08:49 ryoon Exp $

DISTNAME=	tvtime-1.0.2
PKGREVISION=	11
CATEGORIES=	multimedia x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tvtime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tvtime.sourceforge.net/
COMMENT=	High quality television application
LICENSE=	gnu-gpl-v2 AND mit AND gnu-lgpl-v2

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++03
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt aclocal automake autoconf

INSTALLATION_DIRS=	share/examples/tvtime

CONF_FILES=	share/examples/tvtime/tvtime.xml ${PKG_SYSCONFDIR}/tvtime.xml

pre-configure:
	(cd ${WRKSRC} && autoreconf -vif)

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
