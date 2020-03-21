# $NetBSD: Makefile,v 1.15 2020/03/21 16:57:01 bsiegert Exp $

DISTNAME=	xz-0.5.4
PKGNAME=	go-${DISTNAME}
PKGREVISION=	14
MASTER_SITES=	${MASTER_SITE_GITHUB:=ulikunitz/}
CATEGORIES=	archivers
GITHUB_PROJECT=	${PKGBASE:S/^go-//}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/ulikunitz/xz
COMMENT=	Pure golang package for reading and writing xz-compressed files
LICENSE=	modified-bsd

GO_DIST_BASE=	${PKGBASE:S/go-//}-${PKGVERSION_NOREV}
GO_SRCPATH=	${HOMEPAGE:S,https://,,}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
