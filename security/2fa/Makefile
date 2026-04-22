# $NetBSD: Makefile,v 1.85.2.1 2026/04/22 14:32:11 maya Exp $

DISTNAME=	2fa-1.2.0
PKGREVISION=	52
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=rsc/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	2fa

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=rsc/2fa/}
COMMENT=	Command-line client for two-factor authentication
LICENSE=	modified-bsd

pre-configure:
	# Fix build error, invalid vendor/modules.txt.
	${RM} -rf ${WRKSRC}/vendor

do-install:
	# gocopy and gopaste are not required to use 2fa.
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/2fa ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
