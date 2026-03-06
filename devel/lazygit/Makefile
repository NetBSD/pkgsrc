# $NetBSD: Makefile,v 1.68 2026/03/06 21:07:51 bsiegert Exp $

DISTNAME=	lazygit-0.59.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jesseduffield/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jesseduffield/lazygit
COMMENT=	Simple terminal UI for git commands
LICENSE=	mit

INSTALLATION_DIRS+=	bin
GO_BUILD_PATTERN=	.

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/lazygit ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
