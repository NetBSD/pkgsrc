# $NetBSD: Makefile,v 1.11 2018/11/04 18:38:04 bsiegert Exp $

DISTNAME=	go-dns-0.0.20160614
PKGREVISION=	9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=miekg/}
GITHUB_PROJECT=	dns
GITHUB_TAG=	5d001d020961ae1c184f9f8152fdc73810481677

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/miekg/dns
COMMENT=	Complete DNS library for Go
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/miekg/dns

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
