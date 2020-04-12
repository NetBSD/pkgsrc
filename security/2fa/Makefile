# $NetBSD: Makefile,v 1.21 2020/04/12 11:01:45 bsiegert Exp $

DISTNAME=	2fa-1.1.0
PKGREVISION=	9
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=rsc/}
GITHUB_TAG=	v1.1.0
GITHUB_PROJECT=	2fa

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=rsc/2fa/}
COMMENT=	Command-line client for two-factor authentication
LICENSE=	modified-bsd

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	rsc.io/2fa

CHECK_RELRO_SKIP+=	bin/2fa

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/2fa ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
