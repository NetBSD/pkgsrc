# $NetBSD: Makefile,v 1.21.2.1 2026/04/22 14:32:14 maya Exp $

DISTNAME=	Terrapin-Scanner-1.0.3
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	20
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=RUB-NDS/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

WRKSRC=		${WRKDIR}/${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://terrapin-attack.com/
COMMENT=	Scan SSH servers and clients for Terrapin vulnerability
LICENSE=	apache-2.0

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
