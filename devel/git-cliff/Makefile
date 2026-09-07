# $NetBSD: Makefile,v 1.57 2026/09/07 07:10:02 pin Exp $

DISTNAME=	git-cliff-2.14.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=orhun/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git-cliff.org/
COMMENT=	Highly customizable Changelog Generator
LICENSE=	gnu-gpl-v3

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

.include "cargo-depends.mk"

RUST_REQ=		1.88.0
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/git-cliff \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
