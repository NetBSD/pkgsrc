# $NetBSD: Makefile,v 1.6 2021/04/01 16:07:32 fcambus Exp $

DISTNAME=	statzone-1.1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/fcambus/statzone
COMMENT=	DNS zone file analyzer targeted at TLD zones
LICENSE=	2-clause-bsd

USE_LANGUAGES=  c++

USE_CMAKE=	yes

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
