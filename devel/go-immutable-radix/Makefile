# $NetBSD: Makefile,v 1.3 2017/08/25 17:03:26 jperkin Exp $

DISTNAME=	go-immutable-radix-0.0.20170725
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
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
