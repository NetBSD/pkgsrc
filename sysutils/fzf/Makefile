# $NetBSD: Makefile,v 1.1 2017/10/24 06:57:50 maya Exp $

GITHUB_PROJECT=	fzf
DISTNAME=	0.17.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=junegunn/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/junegunn/fzf/
COMMENT=	Command-line fuzzy finder
LICENSE=	mit

USE_TOOLS+=	bash:run

GO_DIST_BASE=	${GITHUB_PROJECT}-${DISTNAME}
GO_SRCPATH=	github.com/junegunn/fzf

REPLACE_BASH+=	bin/fzf-tmux
REPLACE_BASH+=	install
REPLACE_BASH+=	uninstall

CHECK_INTERPRETER_SKIP+=	gopkg/src/github.com/junegunn/fzf/src/update_assets.rb

.include "../../devel/go-isatty/buildlink3.mk"
.include "../../devel/go-shellwords/buildlink3.mk"
.include "../../devel/go-runewidth/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
