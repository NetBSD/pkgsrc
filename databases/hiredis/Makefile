# $NetBSD: Makefile,v 1.11 2023/01/24 18:36:21 wiz Exp $

DISTNAME=	hiredis-1.1.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=redis/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/redis/hiredis
COMMENT=	Minimalistic C client library for the Redis database
LICENSE=	modified-bsd

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}

# needs running redis-server
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ./hiredis-test

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
