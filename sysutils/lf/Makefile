# $NetBSD: Makefile,v 1.94 2026/05/07 18:50:07 bsiegert Exp $

DISTNAME=		lf-34
PKGREVISION=		14
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=gokcehan/}
GITHUB_TAG=		r${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/gokcehan/lf
COMMENT=		Terminal file manager
LICENSE=		2-clause-bsd

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 share/applications share/examples/lf
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/fish/vendor_completions.d
INSTALLATION_DIRS+=	share/zsh/site-functions

post-install:
	${INSTALL_DATA} ${WRKSRC}/lf.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/lf.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/etc/* ${DESTDIR}${PREFIX}/share/examples/lf
	${MV} ${DESTDIR}${PREFIX}/share/examples/lf/lf.bash ${DESTDIR}${PREFIX}/share/bash-completion/completions/lf
	${MV} ${DESTDIR}${PREFIX}/share/examples/lf/lf.fish ${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/lf.fish
	${MV} ${DESTDIR}${PREFIX}/share/examples/lf/lf.zsh ${DESTDIR}${PREFIX}/share/zsh/site-functions/_lf

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
