# $NetBSD: Makefile,v 1.1 2025/08/25 17:43:30 adam Exp $

DISTNAME=	mdBook-0.4.52
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=rust-lang/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rust-lang/mdBook
COMMENT=	Create modern online books from Markdown files
LICENSE=	mpl-2.0

RUST_REQ=	1.82
WRKSRC=		${WRKDIR}/${DISTNAME}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/mdbook ${DESTDIR}${PREFIX}/bin

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
