# $NetBSD: Makefile,v 1.4 2021/07/13 11:36:34 bsiegert Exp $

DISTNAME=		age-${GITHUB_TAG:S/v//:S/-rc./rc/}
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=FiloSottile/}
GITHUB_TAG=		v1.0.0-rc.3

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/FiloSottile/age/
COMMENT=		Simple, modern and secure encryption tool
LICENSE=		modified-bsd

.include "go-modules.mk"

GO_BUILD_PATTERN=	filippo.io/age/cmd/...

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/age ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/age-keygen ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
