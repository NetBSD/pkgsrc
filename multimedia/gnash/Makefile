# $NetBSD: Makefile,v 1.1.1.1 2006/12/05 15:15:24 wiz Exp $
#

DISTNAME=		gnash-0.7.2
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_GNU:=gnash/0.7.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gnash/
COMMENT=		GPL'd Flash movie player

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
# XXX: plugin not enabled yet
#CONFIGURE_ARGS+=	--with-plugindir=${PREFIX}/plugins
CONFIGURE_ARGS+=	--disable-plugin
CONFIGURE_ARGS+=	--enable-mp3
USE_TOOLS+=		bash pkg-config
# /bin/sh finds a syntax error without line number
CONFIG_SHELL=		${LOCALBASE}/bin/bash

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
