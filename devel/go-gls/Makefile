# $NetBSD: Makefile,v 1.17 2019/08/14 15:45:35 bsiegert Exp $

GITHUB_TAG=	v4.2.0
DISTNAME=	gls-${GITHUB_TAG:S/v//}
PKGNAME=	go-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jtolds/}
GITHUB_PROJECT=	gls

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jtolds/gls
COMMENT=	Goroutine local storage
LICENSE=	mit

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/jtolds/gls

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
