# $NetBSD: Makefile,v 1.11 2025/04/05 18:51:26 bsiegert Exp $

DISTNAME=	xhash-3.5.1
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=ricardobranco777/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	rbranco@suse.de
HOMEPAGE=	https://github.com/ricardobranco777/xhash
COMMENT=	Faster hashing with Goroutines
LICENSE=	mit

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
