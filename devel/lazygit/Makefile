# $NetBSD: Makefile,v 1.70 2026/04/08 05:44:57 bsiegert Exp $

DISTNAME=	lazygit-0.60.0
PKGREVISION=	1
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
