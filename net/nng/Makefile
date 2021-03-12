# $NetBSD: Makefile,v 1.1 2021/03/12 02:28:08 khorben Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-1.4.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=nanomsg/}
GITHUB_PROJECT=	nng
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nng.nanomsg.org/
COMMENT=	Light-weight brokerless messaging
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c99 c++

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
