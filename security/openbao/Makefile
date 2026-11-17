# $NetBSD: Makefile,v 1.1 2026/11/17 21:15:01 bsiegert Exp $

DISTNAME=	openbao-dist-v2.7.2
PKGNAME=	${DISTNAME:S,-dist-v,-,}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=openbao/openbao/releases/download/v${PKGVERSION_NOREV}}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://openbao.org/
COMMENT=	Store for secrets, certificates and keys
LICENSE=	mpl-2.0

GO_BUILD_PATTERN=	.

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/openbao ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
