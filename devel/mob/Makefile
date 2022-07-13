# $NetBSD: Makefile,v 1.51 2022/07/13 16:03:08 bsiegert Exp $

DISTNAME=	${GITHUB_PROJECT}-3.1.4
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=remotemobprogramming/}
GITHUB_PROJECT=	mob
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://mob.sh/
COMMENT=	Swift git handover during remote mob programming
LICENSE=	mit

GO_BUILD_PATTERN=	.

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -s mob ensemble

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
