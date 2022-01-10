# $NetBSD: Makefile,v 1.6 2022/01/10 01:46:45 ryoon Exp $

DISTNAME=	libkolabxml-1.1.6
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	https://mirror.kolabenterprise.com/pub/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kolab.org/
COMMENT=	Kolab XML Format Schema Definitions Library
LICENSE=	apache-2.0 AND gnu-lgpl-v3

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	gmake

CMAKE_ARGS+=	-DBUILD_TESTS=OFF

SUBST_CLASSES+=		pathes
SUBST_STAGE.pathes=	post-install
SUBST_FILES.pathes=	${DESTDIR}${PREFIX}/lib/cmake/Libkolabxml/LibkolabxmlTargets-noconfig.cmake
SUBST_SED.pathes=	-e "s,${BUILDLINK_DIR},${PREFIX},g"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/xsd/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
