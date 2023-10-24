# $NetBSD: Makefile,v 1.9 2023/10/24 22:11:15 wiz Exp $

DISTNAME=	tealdeer-1.6.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=dbrgn/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/dbrgn/tealdeer/
COMMENT=	Simplified, example based and community-driven man pages
LICENSE=	mit OR apache-2.0

MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
INSTALLATION_DIRS=	bin share/bash-completion/completions

.include "cargo-depends.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/tldr \
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/completion/bash_tealdeer \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/tldr

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
