# $NetBSD: Makefile,v 1.1 2019/10/28 17:46:58 agc Exp $

DISTNAME=	libstark-20191018
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=elibensasson/}
GITHUB_PROJECT=	libSTARK
GITHUB_TAG=	11c72adf909e259aa20a36317e22108784f6dd73

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/elibensasson/
COMMENT=	Library for succinct non-interactive zero knowledge proofs
LICENSE=	mit

BUILD_TARGET=	default
TEST_TARGET=	tests

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++11

AUTO_MKDIRS=	yes

do-install:
	for f in stark-dpm stark-tinyram; do				\
		${INSTALL_PROGRAM} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/bin/; \
	done

.include "../../devel/googletest/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
