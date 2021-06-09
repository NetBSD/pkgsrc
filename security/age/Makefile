# $NetBSD: Makefile,v 1.1.1.1 2021/06/09 17:03:49 abs Exp $

DISTNAME=		age-${GITHUB_TAG:S/v//:S/-rc./rc/}
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=FiloSottile/}
GITHUB_TAG=		v1.0.0-rc.2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/FiloSottile/age/
COMMENT=		Simple, modern and secure encryption tool
LICENSE=		modified-bsd

GO_BUILD_PATTERN=	filippo.io/age/cmd/...

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/age ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/age-keygen ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
