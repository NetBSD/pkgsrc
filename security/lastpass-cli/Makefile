# $NetBSD: Makefile,v 1.40 2025/09/08 08:09:18 vins Exp $

DISTNAME=	lastpass-cli-1.6.1
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=lastpass/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/lastpass/lastpass-cli/
COMMENT=	Command line interface to LastPass.com
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	asciidoc>=0:../../textproc/asciidoc

USE_LANGUAGES=	c c++
USE_TOOLS=	bash:test pkg-config

# Do not warn about deprecated declarations when using OpenSSL 3.x
CFLAGS+=	-Wno-deprecated-declarations

REPLACE_BASH+=	test/askpass-wrong.sh test/askpass.sh \
		test/assert.sh test/include.sh test/tests

CMAKE_CONFIGURE_ARGS=	-DOPENSSL_ROOT_DIR=${SSLBASE}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

INSTALL_TARGET=	install install-doc
TEST_TARGET=	lpass-test test

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
