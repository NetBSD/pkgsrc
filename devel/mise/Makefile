# $NetBSD: Makefile,v 1.14 2024/05/08 16:22:30 schmonz Exp $

DISTNAME=		mise-2024.5.3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=jdx/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://mise.jdx.dev/
COMMENT=		Polyglot tool version manager like asdf
LICENSE=		mit

USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config

.include "cargo-depends.mk"

AUTO_MKDIRS=		yes

.PHONY: maintainer-mise-changelog
MISE_CHANGELOG_VERSION?=${PKGVERSION_NOREV}
maintainer-mise-changelog:
	@fetch -q -o - ${MASTER_SITES}mise/releases/tag/v${MISE_CHANGELOG_VERSION} \
	| html2text --ignore-links --ignore-emphasis - \
	| awk '/^v${MISE_CHANGELOG_VERSION}/{flag=1} /^Assets /{flag=0} flag' \
	| awk '/^This .* was /{flag=1} /^Learn about vigilant mode\.$$/{flag=0; next} !flag' \
	| perl -pe 's/[^[:ascii:]]//g' \
	| sed -e 's|#  |# |g' \
		-e 's|^# v||' \
		-e 's| by .* in .*$$||' \
		-e 's|^  \*|*|g'

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
