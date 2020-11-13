# $NetBSD: Makefile,v 1.27 2020/11/13 19:26:18 bsiegert Exp $

DISTNAME=	go-ovh-0.20170102
PKGREVISION=	26
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ovh/}
GITHUB_PROJECT=	go-ovh
GITHUB_TAG=	d2207178e10e4527e8f222fd8707982df8c3af17

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://${GO_SRCPATH}
COMMENT=	Lightweight Go wrapper around OVH APIs
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/ovh/go-ovh

.include "../../devel/go-ini/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
