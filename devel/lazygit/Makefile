# $NetBSD: Makefile,v 1.38 2024/02/07 14:50:49 bsiegert Exp $

DISTNAME=		lazygit-0.40.2
PKGREVISION=		8
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=jesseduffield/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/jesseduffield/lazygit/
COMMENT=		Simple terminal UI for git commands
LICENSE=		mit

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/lazygit ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
