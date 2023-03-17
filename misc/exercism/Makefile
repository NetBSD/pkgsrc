# $NetBSD: Makefile,v 1.2 2023/03/17 11:39:18 schmonz Exp $

DISTNAME=		cli-3.1.0
PKGNAME=		${DISTNAME:S/^cli-/exercism-/}
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GITHUB:=exercism/}
GITHUB_PROJECT=		cli
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://exercism.org/
COMMENT=		Command line tool for exercism.org
LICENSE=		mit

USE_LANGUAGES=		# none

AUTO_MKDIRS=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/shell/exercism_completion.bash		\
		${DESTDIR}${PREFIX}/share/bash-completion/completions/exercism
	${INSTALL_DATA} ${WRKSRC}/shell/exercism.fish				\
		${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/exercism.fish
	${INSTALL_DATA} ${WRKSRC}/shell/exercism_completion.zsh			\
		${DESTDIR}${PREFIX}/share/zsh/site-functions/_exercism

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
