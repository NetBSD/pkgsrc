# $NetBSD: Makefile,v 1.55 2022/07/13 16:03:05 bsiegert Exp $

DISTNAME=	fzf-0.29.0
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=junegunn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/junegunn/fzf/
COMMENT=	Command-line fuzzy finder
LICENSE=	mit

USE_TOOLS+=	bash:run

GO_BUILD_PATTERN=	.

.include "go-modules.mk"

REPLACE_BASH+=	bin/fzf-tmux

FZF_SHELL_FILES+=	completion.bash completion.zsh
FZF_SHELL_FILES+=	key-bindings.bash key-bindings.fish key-bindings.zsh

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 share/fzf/plugin share/fzf/shell

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/fzf-tmux ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/fzf.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/man1/fzf-tmux.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/plugin/fzf.vim ${DESTDIR}${PREFIX}/share/fzf/plugin
.for f in ${FZF_SHELL_FILES}
	${INSTALL_DATA} ${WRKSRC}/shell/${f} ${DESTDIR}${PREFIX}/share/fzf/shell
.endfor

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
