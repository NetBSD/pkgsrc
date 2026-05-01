# $NetBSD: Makefile,v 1.3 2026/05/01 10:11:05 fox Exp $

DISTNAME=	edit-2.0.0
PKGNAME=	ms${DISTNAME}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=microsoft/}
GITHUB_PROJECT=	edit
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/edit/
COMMENT=	Simple editor for simple needs
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}

RUST_REQ=	1.93

INSTALLATION_DIRS=	bin

MAKE_ENV+=	RUSTC_BOOTSTRAP=1

.include "cargo-depends.mk"

do-install:
	cargo install --path ${WRKSRC}/crates/edit
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/edit \
		${DESTDIR}${PREFIX}/bin/msedit

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
