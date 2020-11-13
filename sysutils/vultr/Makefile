# $NetBSD: Makefile,v 1.25 2020/11/13 19:26:22 bsiegert Exp $

DISTNAME=		v${VERSION}
PKGNAME=		${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
PKGREVISION=		8
VERSION=		2.0.1
GITHUB_PROJECT=		vultr
GITHUB_TAG=		${DISTNAME}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=JamesClonk/}
DIST_SUBDIR=		${GITHUB_PROJECT}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://jamesclonk.github.io/vultr/
COMMENT=		CLI and API client library for Vultr
LICENSE=		mit

GO_DIST_BASE=		${PKGNAME_NOREV}
GO_SRCPATH=		github.com/JamesClonk/vultr

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/vultr ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
