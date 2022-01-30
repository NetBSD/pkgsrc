# $NetBSD: Makefile,v 1.37 2022/01/30 20:27:52 schmonz Exp $

DISTNAME=	${GITHUB_PROJECT}-2.3.0
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
