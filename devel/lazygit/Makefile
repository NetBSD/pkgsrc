# $NetBSD: Makefile,v 1.8 2021/12/09 17:50:18 bsiegert Exp $

DISTNAME=		lazygit-0.31.4
PKGREVISION=		1
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
