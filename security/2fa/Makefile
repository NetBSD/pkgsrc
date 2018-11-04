# $NetBSD: Makefile,v 1.6 2018/11/04 18:38:06 bsiegert Exp $

DISTNAME=	2fa
PKGNAME=	2fa-20171122
PKGREVISION=	4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=rsc/}
GITHUB_TAG=	c9558c536f6538d59f1b012915b44e44e3563823

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=rsc/2fa/}
COMMENT=	Command-line client for two-factor authentication
LICENSE=	modified-bsd

GO_DIST_BASE=	2fa-${GITHUB_TAG}
GO_SRCPATH=	rsc.io/2fa

CHECK_RELRO_SKIP+=	bin/2fa

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/2fa ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
