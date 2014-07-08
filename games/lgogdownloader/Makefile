# $NetBSD: Makefile,v 1.3 2014/07/08 14:59:40 jperkin Exp $

DISTNAME=	lgogdownloader-2.13
PKGREVISION=	1
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
LDFLAGS+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.boost-libs}/lib

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		json
SUBST_SED.json+=	-e 's,jsoncpp/json/json.h,json/json.h,'
SUBST_FILES.json+=	src/api.cpp src/downloader.cpp
SUBST_STAGE.json=	post-configure
SUBST_MESSAGE.json=	Fixing path to jsoncpp headers.

post-build:
	cd ${WRKSRC}/man && gunzip lgogdownloader.1
do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} bin/Release/lgogdownloader ${DESTDIR}${PREFIX}/bin && \
		${INSTALL_DATA} man/lgogdownloader.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/liboauth/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../www/htmlcxx/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../misc/rhash/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
