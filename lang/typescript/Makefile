# $NetBSD: Makefile,v 1.5 2026/11/10 18:55:10 bsiegert Exp $

DISTNAME=	typescript-7.0.2
PKGREVISION=	3
CATEGORIES=	lang
GITHUB_PROJECT=	TypeScript
GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=microsoft/}

MAINTAINER=	kikadf@NetBSD.org
HOMEPAGE=	https://www.typescriptlang.org/
COMMENT=	Superset of JavaScript that compiles to clean JavaScript output
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}/tsc

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
