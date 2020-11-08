# $NetBSD: Makefile,v 1.7 2020/11/08 21:59:17 bsiegert Exp $

DISTNAME=	go-gospel-0.0.20200416
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=bfix/}
GITHUB_TAG=	1d04e847bea4171138af65e5dbba9c8376fd7795
GITHUB_PROJECT=	gospel

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/bfix/gospel/
COMMENT=	GO SPEcial Library
LICENSE=	gnu-gpl-v3

GO_SRCPATH=	github.com/bfix/gospel
GO_DIST_BASE=	gospel-${GITHUB_TAG}*

.include "../../security/go-crypto/buildlink3.mk"
.include "../../textproc/go-text/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
