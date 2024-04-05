# $NetBSD: Makefile,v 1.8 2024/04/05 19:14:10 bsiegert Exp $

DISTNAME=	autorestic-1.7.9
PKGREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=cupcakearmy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cupcakearmy/autorestic/
COMMENT=	Config driven, easy backup CLI for restic
LICENSE=	apache-2.0

USE_LANGUAGES=	c

.include "go-modules.mk"

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/build

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
