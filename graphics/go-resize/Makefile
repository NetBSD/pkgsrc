# $NetBSD: Makefile,v 1.15 2020/03/21 16:57:17 bsiegert Exp $

DISTNAME=	resize-0.0.20180221
PKGNAME=	go-${DISTNAME}
PKGREVISION=	14
MASTER_SITES=	${MASTER_SITE_GITHUB:=nfnt/}
CATEGORIES=	graphics
GITHUB_PROJECT=	${PKGBASE:S/^go-//}
GITHUB_TAG=	83c6a9932646f83e3267f353373d47347b6036b2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/nfnt/resize
COMMENT=	Pure Go image resizing
LICENSE=	isc

GO_DIST_BASE=	${PKGBASE:S/go-//}-${GITHUB_TAG}
GO_SRCPATH=	${HOMEPAGE:S,https://,,}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
