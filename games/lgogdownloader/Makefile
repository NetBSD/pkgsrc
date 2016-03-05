# $NetBSD: Makefile,v 1.20 2016/03/05 11:28:34 jperkin Exp $

DISTNAME=	lgogdownloader-2.26
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

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/liboauth/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../www/htmlcxx/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../misc/rhash/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
