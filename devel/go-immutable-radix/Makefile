# $NetBSD: Makefile,v 1.22 2020/06/17 09:54:05 bsiegert Exp $

DISTNAME=	go-immutable-radix-0.0.20170725
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
PKGREVISION=	19
CATEGORIES=	devel
GITHUB_TAG=	8aac2701530899b64bdea735a1de8da899815220

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hashicorp/go-immutable-radix
COMMENT=	Immutable radix tree implementation in Golang
LICENSE=	mpl-2.0

GO_DIST_BASE=	${DISTNAME}
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/hashicorp/go-immutable-radix

.include "../../devel/go-golang-lru/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
