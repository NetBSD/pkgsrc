# $NetBSD: Makefile,v 1.25 2025/09/27 09:57:37 wiz Exp $

DISTNAME=	libkolabxml-1.1.6
PKGREVISION=	22
CATEGORIES=	textproc
MASTER_SITES=	https://mirror.kolabenterprise.com/pub/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kolab.org/
COMMENT=	Kolab XML Format Schema Definitions Library
LICENSE=	apache-2.0 AND gnu-lgpl-v3

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	gmake

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/xsd/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
