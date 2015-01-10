# $NetBSD: Makefile,v 1.13 2015/01/10 20:25:57 wiz Exp $

DISTNAME=	lgogdownloader-2.20
CATEGORIES=	games
MASTER_SITES=	http://sites.google.com/site/gogdownloader/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Sude-/lgogdownloader
COMMENT=	Download games from GOG
#LICENSE=	dwtfywtpl

BUILD_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

#WRKSRC=		${WRKDIR}/lgogdownloader
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake gunzip

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

SUBST_CLASSES+=		json
SUBST_SED.json+=	-e 's,jsoncpp/json/json.h,json/json.h,'
SUBST_FILES.json+=	include/downloader.h include/gamedetails.h include/gamefile.h
SUBST_FILES.json+=	src/api.cpp src/downloader.cpp src/util.cpp
SUBST_STAGE.json=	post-configure
SUBST_MESSAGE.json=	Fixing path to jsoncpp headers.

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/liboauth/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../www/htmlcxx/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../misc/rhash/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
