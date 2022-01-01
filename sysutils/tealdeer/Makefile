# $NetBSD: Makefile,v 1.6 2022/01/01 19:32:04 bsiegert Exp $

DISTNAME=	tealdeer-1.5.0
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=dbrgn/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/dbrgn/tealdeer/
COMMENT=	Simplified, example based and community-driven man pages
LICENSE=	mit OR apache-2.0

USE_LANGUAGES=	c # rust

MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
INSTALLATION_DIRS=	bin share/bash-completion/completions

.include "cargo-depends.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/tldr ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/bash_tealdeer ${DESTDIR}${PREFIX}/share/bash-completion/completions/tldr

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
# $NetBSD: Makefile,v 1.6 2022/01/01 19:32:04 bsiegert Exp $

