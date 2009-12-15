# $NetBSD: Makefile,v 1.23 2009/12/15 21:59:05 joerg Exp $
#

DISTNAME=		gnash-${VER}
VER=			0.8.3
PKGREVISION=		7
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_GNU:=gnash/${VER}/}
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
# for appending below
INSTALL_TARGET=		install

# /bin/sh finds a syntax error without line number
CONFIG_SHELL=		${TOOLS_BASH}

EGDIR=			${PREFIX}/share/examples/gnash
INSTALLATION_DIRS=	${EGDIR}
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}
CONF_FILES+=		${EGDIR}/gnashpluginrc ${PKG_SYSCONFDIR}/gnashpluginrc
CONF_FILES+=		${EGDIR}/gnashrc ${PKG_SYSCONFDIR}/gnashrc

.include "options.mk"

PLIST_SRC+=		${PKGDIR}/PLIST

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
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
