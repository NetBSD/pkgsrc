# $NetBSD: Makefile,v 1.26 2021/03/02 13:10:34 ryoon Exp $

DISTNAME=	cbindgen-0.18.0
CATEGORIES=	devel
EXTRACT_SUFX=	.crate

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/eqrion/cbindgen/
COMMENT=	Generating C bindings from Rust code
LICENSE=	mpl-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cbindgen ${DESTDIR}${PREFIX}/bin

RUST_RUNTIME=	yes
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
