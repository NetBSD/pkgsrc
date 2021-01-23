# $NetBSD: Makefile,v 1.15 2021/01/23 14:23:07 bsiegert Exp $

GITHUB_TAG=		ceec8f93295a060cdb565ec25e4ccf17941dbd55
DISTNAME=		go-tcplisten-0.0.0.20161114
PKGREVISION=		13
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=valyala/}
GITHUB_PROJECT=		tcplisten

MAINTAINER=		nikita@NetBSD.org
HOMEPAGE=		https://github.com/valyala/tcplisten/
COMMENT=		Customizable TCP net.Listener for Go
LICENSE=		mit

GO_SRCPATH=		github.com/valyala/tcplisten
GO_DIST_BASE=		tcplisten-${GITHUB_TAG}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
