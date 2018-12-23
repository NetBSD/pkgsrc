# $NetBSD: Makefile,v 1.1 2018/12/23 17:22:21 wiz Exp $

DISTNAME=	json-schema-1.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=nfotex/}
GITHUB_RELEASE=	${DISTNAME}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://github.com/nfotex/json-schema/
COMMENT=	C++ library to validate JSON documents against JSON Schemata
LICENSE=	modified-bsd

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		perl:test pkg-config
TEST_TARGET=		test

.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
