# $NetBSD: Makefile,v 1.5 2023/11/20 14:42:52 pin Exp $

DISTNAME=		sheldon-0.7.4
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_GITHUB:=rossmacarthur/}
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/rossmacarthur/sheldon/
COMMENT=		Fast, configurable shell plugin manager
LICENSE=		apache-2.0

.include "cargo-depends.mk"

USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config

AUTO_MKDIRS=		yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/
	${INSTALL_DATA} ${WRKSRC}/completions/${PKGBASE}.bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/completions/${PKGBASE}.zsh \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/_${PKGBASE}
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/${PKGBASE} ${DESTDIR}${PREFIX}/bin/

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
