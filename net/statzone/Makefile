# $NetBSD: Makefile,v 1.2 2020/06/10 17:43:37 fcambus Exp $

DISTNAME=	statzone-1.0.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/fcambus/statzone
COMMENT=	DNS zone file analyzer targeted at TLD zones
LICENSE=	2-clause-bsd

USE_CMAKE=	yes

TEST_TARGET=	test

.include "../../devel/uthash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
