# $NetBSD: Makefile,v 1.5 2007/01/17 23:47:22 wiz Exp $
#

DISTNAME=		gnash-0.7.2
PKGREVISION=		1
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_GNU:=gnash/0.7.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gnash/
COMMENT=		GPL Flash movie player

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-mp3
USE_TOOLS+=		bash msgfmt pkg-config

# /bin/sh finds a syntax error without line number
CONFIG_SHELL=		${LOCALBASE}/bin/bash

.include "options.mk"

PLIST_SRC+=		${PKGDIR}/PLIST

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
