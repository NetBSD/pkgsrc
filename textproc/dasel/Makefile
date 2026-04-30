# $NetBSD: Makefile,v 1.24 2026/04/30 18:37:30 wiz Exp $

DISTNAME=	dasel-3.8.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=TomWright/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TomWright/dasel/
COMMENT=	Select, put and delete data from JSON, TOML, YAML, XML and CSV
LICENSE=	mit

USE_LANGUAGES=	c

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/fish/vendor_completions.d
INSTALLATION_DIRS+=	share/zsh/site-functions

# dasel binary not available before 'install'
post-install:
	${DESTDIR}${PREFIX}/bin/dasel man > ${WRKSRC}/dasel.1
	${DESTDIR}${PREFIX}/bin/dasel completion bash > ${WRKSRC}/dasel.bash
	${DESTDIR}${PREFIX}/bin/dasel completion fish > ${WRKSRC}/dasel.fish
	${DESTDIR}${PREFIX}/bin/dasel completion zsh > ${WRKSRC}/dasel.zsh
	${INSTALL_DATA} ${WRKSRC}/dasel.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/dasel.bash ${DESTDIR}${PREFIX}/share/bash-completion/completions/dasel
	${INSTALL_DATA} ${WRKSRC}/dasel.fish ${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/dasel.fish
	${INSTALL_DATA} ${WRKSRC}/dasel.zsh ${DESTDIR}${PREFIX}/share/zsh/site-functions/_dasel

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
