# $NetBSD: Makefile,v 1.1 2022/12/28 20:18:21 nikita Exp $

DISTNAME=	nlohmann-json-3.11.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=nlohmann/}
GITHUB_PROJECT=	json
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://json.nlohmann.me/
COMMENT=	JSON library for Modern C++
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11
# FIXME: Downloads test data from a fixed tag in a git repository,
# package https://github.com/nlohmann/json_test_data to prevent downloads.
# FIXME: A small number of tests assume that WRKSRC is a git checkout.
TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
