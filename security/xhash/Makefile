# $NetBSD: Makefile,v 1.3 2024/06/01 14:03:01 bsiegert Exp $

DISTNAME=	xhash-3.3.2
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
