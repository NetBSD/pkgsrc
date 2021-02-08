# $NetBSD: Makefile,v 1.5 2021/02/08 20:38:23 fcambus Exp $

DISTNAME=	statzone-1.0.5
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
