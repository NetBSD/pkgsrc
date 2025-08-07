# $NetBSD: Makefile,v 1.4 2025/08/07 07:36:01 adam Exp $

DISTNAME=	rav1e-0.8.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=xiph/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/xiph/rav1e
COMMENT=	Fastest and safest AV1 encoder by Xiph
LICENSE=	2-clause-bsd

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
TOOL_DEPENDS+=	nasm>=2.14:../../devel/nasm
.endif
TOOL_DEPENDS+=	cargo-c-[0-9]*:../../devel/cargo-c
TOOL_DEPENDS+=	cbindgen-[0-9]*:../../devel/cbindgen

USE_TOOLS+=	pkg-config

.include "cargo-depends.mk"

# Ommit 'git_version' feature, which required libgit2.
# See Cargo.toml for a list of default features.
CARGO_NO_DEFAULT_FEATURES=	yes
CARGO_FEATURES=			binaries asm threading signal_support

# Also build shared library.
CARGOC_ARGS=	--release --destdir ${DESTDIR} --prefix ${PREFIX}

.PHONY: do-cargoc-build
do-cargoc-build:
	${RUN} cd ${CARGO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${CARGO} \
		cbuild ${CARGOC_ARGS} ${DEFAULT_CARGO_ARGS}

do-build: do-cargo-build do-cargoc-build

.PHONY: do-cargoc-install
do-cargoc-install:
	${RUN} cd ${CARGO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${CARGO} \
		cinstall ${CARGOC_ARGS} ${DEFAULT_CARGO_ARGS}

do-install: do-cargo-install do-cargoc-install

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
