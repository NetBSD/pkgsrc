# $NetBSD: Makefile,v 1.23 2020/06/17 09:54:15 bsiegert Exp $

DISTNAME=	hcl-0.0.20160616
PKGNAME=	go-${DISTNAME}
PKGREVISION=	19
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
CATEGORIES=	lang
GITHUB_TAG=	d7400db7143f8e869812e50a53acd6c8d92af3b8
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hashicorp/hcl
COMMENT=	HCL is a configuration language
LICENSE=	mpl-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/hashicorp/hcl

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
