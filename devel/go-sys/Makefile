# $NetBSD: Makefile,v 1.49 2022/01/09 20:10:32 bsiegert Exp $
#

DISTNAME=		go-sys-0.0.20200202
PKGREVISION=		24
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		sys
GITHUB_TAG=		d101bd2416

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://golang.org/
COMMENT=		Go packages for low-level interaction with the OS
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/sys
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

USE_TOOLS+=		bash:run

REPLACE_BASH+=		plan9/*.sh unix/*.sh windows/*.bash

pre-patch:
	${RM} -rf ${WRKSRC}/windows/mkwinsyscall

pre-build:
	${RM} -f ${WRKSRC}/*/*.go.orig

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
