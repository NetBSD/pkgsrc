# $NetBSD: Makefile,v 1.32 2020/11/13 19:26:21 bsiegert Exp $

DISTNAME=	fzf-0.23.1
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=junegunn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/junegunn/fzf/
COMMENT=	Command-line fuzzy finder
LICENSE=	mit

USE_TOOLS+=	bash:run

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/junegunn/fzf

REPLACE_BASH+=	bin/fzf-tmux

FZF_SHELL_FILES+=	completion.bash completion.zsh
FZF_SHELL_FILES+=	key-bindings.bash key-bindings.fish key-bindings.zsh

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/fzf/plugin share/fzf/shell

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/fzf ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/fzf-tmux ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/fzf.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/man1/fzf-tmux.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/plugin/fzf.vim ${DESTDIR}${PREFIX}/share/fzf/plugin
.for f in ${FZF_SHELL_FILES}
	${INSTALL_DATA} ${WRKSRC}/shell/${f} ${DESTDIR}${PREFIX}/share/fzf/shell
.endfor

.include "../../devel/go-isatty/buildlink3.mk"
.include "../../devel/go-shellwords/buildlink3.mk"
.include "../../devel/go-walker/buildlink3.mk"
.include "../../textproc/go-runewidth/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
