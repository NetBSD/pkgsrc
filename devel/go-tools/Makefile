# $NetBSD: Makefile,v 1.2 2015/09/13 14:34:25 bsiegert Exp $
#

DISTNAME=		tools
PKGNAME=		go-tools-20150504
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		${DISTNAME}
GITHUB_TAG=		d00f0cb57d

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		Tools for use with Go, including godoc
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/tools
GO_DIST_BASE=		${DISTNAME}-${GITHUB_TAG}*

.include "../../lang/go/go-package.mk"

INSTALLATION_DIRS+=	${GOTOOLDIR}

post-install:
	mv ${DESTDIR}${PREFIX}/bin/cover ${DESTDIR}${GOTOOLDIR}
	mv ${DESTDIR}${PREFIX}/bin/vet ${DESTDIR}${GOTOOLDIR}

.include "../../devel/google-api-go-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
