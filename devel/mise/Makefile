# $NetBSD: Makefile,v 1.22 2024/06/01 19:17:45 schmonz Exp $

DISTNAME=		mise-2024.5.28
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=jdx/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://mise.jdx.dev/
COMMENT=		Polyglot tool version manager like asdf
LICENSE=		mit

USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config

.include "cargo-depends.mk"

AUTO_MKDIRS=		yes

post-install:
	${TOUCH} ${DESTDIR}${PREFIX}/lib/mise/.disable-self-update
	${INSTALL_DATA} ${WRKSRC}/man/man1/mise.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/completions/mise.bash		\
		${DESTDIR}${PREFIX}/share/bash-completion/completions/mise
	${INSTALL_DATA} ${WRKSRC}/completions/mise.fish		\
		${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/mise.fish
	${INSTALL_DATA} ${WRKSRC}/completions/_mise		\
		${DESTDIR}${PREFIX}/share/zsh/site-functions/

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
