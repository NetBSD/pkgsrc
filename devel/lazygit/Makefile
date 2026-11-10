# $NetBSD: Makefile,v 1.94 2026/11/10 12:28:29 adam Exp $

DISTNAME=	lazygit-0.66.3
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
