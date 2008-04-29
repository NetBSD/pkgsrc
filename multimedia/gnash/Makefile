# $NetBSD: Makefile,v 1.15 2008/04/29 20:16:08 wiz Exp $
#

DISTNAME=		gnash-0.8.2
PKGREVISION=		1
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_GNU:=gnash/0.8.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		matias@dotbsd.org
HOMEPAGE=		http://www.gnashdev.org/
COMMENT=		GPL Flash movie player

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		bash gmake msgfmt pkg-config
CONFIGURE_ARGS+=	--with-npapi-plugindir=${PREFIX}/lib/firefox/plugins
# for appending below
INSTALL_TARGET=		install

# /bin/sh finds a syntax error without line number
CONFIG_SHELL=		${TOOLS_BASH}

.include "options.mk"

PLIST_SRC+=		${PKGDIR}/PLIST

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
