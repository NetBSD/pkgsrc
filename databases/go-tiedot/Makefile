# $NetBSD: Makefile,v 1.8 2020/06/17 09:54:14 bsiegert Exp $

GITHUB_PROJECT=	tiedot
GITHUB_TAG=	${PKGVERSION_NOREV}
DISTNAME=	3.4
PKGNAME=	go-${GITHUB_PROJECT}-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=HouzuoGuo/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/HouzuoGuo/tiedot/
COMMENT=	NoSQL database in Go
LICENSE=	2-clause-bsd

GO_SRCPATH=	github.com/HouzuoGuo/tiedot
GO_DIST_BASE=	tiedot-${PKGVERSION_NOREV}

.include "../../devel/go-jwt-go/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
