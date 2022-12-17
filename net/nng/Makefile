# $NetBSD: Makefile,v 1.3 2022/12/17 14:25:20 he Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-1.4.0
PKGREVISION=	1
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

.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
