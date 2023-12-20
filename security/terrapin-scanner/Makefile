# $NetBSD: Makefile,v 1.2 2023/12/20 18:47:06 abs Exp $

DISTNAME=	Terrapin-Scanner-1.0.3
PKGNAME=	${DISTNAME:tl}
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
