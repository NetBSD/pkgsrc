# $NetBSD: Makefile,v 1.15 2020/06/17 09:54:15 bsiegert Exp $

DISTNAME=		mkcert-${GITHUB_TAG}
PKGNAME=		go-mkcert-${VERSION}
PKGREVISION=		14
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=FiloSottile/}
GITHUB_PROJECT=		mkcert
VERSION=		1.2.0
GITHUB_TAG=		v${VERSION}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/FiloSottile/mkcert/
COMMENT=		Make locally trusted development certificates
LICENSE=		modified-bsd

GO_DIST_BASE=		mkcert-${VERSION}
GO_SRCPATH=		github.com/FiloSottile/mkcert

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/mkcert ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
