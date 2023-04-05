# $NetBSD: Makefile,v 1.7 2023/04/05 20:47:45 bsiegert Exp $

DISTNAME=	ipget-0.9.1
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ipfs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ipfs/ipget/
COMMENT=	Retrieve files over IPFS and save them locally
LICENSE=	mit

# does not support go 1.19 yet (as of 0.9.1)
GO_VERSION_DEFAULT=	118

USE_LANGUAGES=	c # go

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
