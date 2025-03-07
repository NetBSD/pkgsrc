# $NetBSD: Makefile,v 1.48 2025/03/07 20:54:18 bsiegert Exp $

DISTNAME=		lazygit-0.47.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=jesseduffield/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/jesseduffield/lazygit/
COMMENT=		Simple terminal UI for git commands
LICENSE=		mit

INSTALLATION_DIRS+=	bin
GO_BUILD_PATTERN=	.

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/lazygit ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
