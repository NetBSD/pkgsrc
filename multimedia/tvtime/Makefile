# $NetBSD: Makefile,v 1.1.1.1 2008/09/15 13:15:46 jmcneill Exp $

DISTNAME=	tvtime-1.0.1
CATEGORIES=	multimedia x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tvtime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tvtime.sourceforge.net/
COMMENT=	High quality television application

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt aclocal automake autoconf

pre-configure:
	(cd ${WRKSRC} && autoreconf -vif)

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
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
