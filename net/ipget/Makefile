# $NetBSD: Makefile,v 1.11 2023/08/26 16:31:32 bsiegert Exp $

DISTNAME=	ipget-0.9.2
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ipfs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ipfs/ipget/
COMMENT=	Retrieve files over IPFS and save them locally
LICENSE=	mit

USE_LANGUAGES=	c # go

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
