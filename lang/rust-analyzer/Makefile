# $NetBSD: Makefile,v 1.7 2022/02/06 16:49:03 adam Exp $

DISTNAME=	rust-analyzer-2022-01-31
PKGNAME=	${DISTNAME:C/-2([0-9]*)-([0-9]*)-([0-9]*)/-0.0.2\1.\2.\3/}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=rust-analyzer/}
GITHUB_PROJECT=	rust-analyzer
GITHUB_TAG=	${DISTNAME:S/rust-analyzer-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rust-analyzer/rust-analyzer/
COMMENT=	Rust compiler front-end for IDEs
LICENSE=	apache-2.0

DEPENDS+=	rust-src-[0-9]*:../../lang/rust-src

INSTALLATION_DIRS=	bin
USE_LANGUAGES=		c c++

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rust-analyzer ${DESTDIR}${PREFIX}/bin

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
