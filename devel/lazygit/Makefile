# $NetBSD: Makefile,v 1.19 2022/10/05 11:33:00 bsiegert Exp $

DISTNAME=		lazygit-0.31.4
PKGREVISION=		12
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
