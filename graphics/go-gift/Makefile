# $NetBSD: Makefile,v 1.11 2021/05/08 15:02:28 bsiegert Exp $

DISTNAME=		go-gift-1.2.1
PKGREVISION=		9
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GITHUB:=disintegration/}
GITHUB_PROJECT=		gift
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/disintegration/gift
COMMENT=		Go Image Filtering Toolkit
LICENSE=		mit

GO_SRCPATH=		github.com/disintegration/gift
GO_DIST_BASE=		${DISTNAME:S/go-//}


.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
