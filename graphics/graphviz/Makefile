# $NetBSD: Makefile,v 1.33 2005/04/28 14:58:06 wiz Exp $
#

DISTNAME=	graphviz-2.2.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.graphviz.org/pub/graphviz/ARCHIVE/

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://www.graphviz.org/
COMMENT=	Graph Drawing Programs from AT&T Research and Lucent Bell Labs

LICENSE=	graphviz-license

DIST_SUBDIR=	${PKGNAME_NOREV}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_X11=		yes
XAW_TYPE=		standard
PKGCONFIG_OVERRIDE=	*/*.pc */*/*.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ENV+=		TCLCONFIG=${TCLCONFIG_SH}
CONFIGURE_ENV+=		TKCONFIG=${TKCONFIG_SH}
CONFIGURE_ENV+=		X11PREFIX=${X11PREFIX} X11BASE=${X11BASE}

# Dynagraph is left out for now
#UNLIMIT_RESOURCES=	datasize stacksize memorysize
CONFIGURE_ARGS+=	--without-dynagraph

# the upstream tarball still contains *.orig files
post-extract:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

# prevent another config.status run
pre-build:
	${TOUCH} ${WRKSRC}/Makefile

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
