# $NetBSD: Makefile,v 1.3 2023/10/24 22:10:10 wiz Exp $

DISTNAME=	rav1e-0.6.3
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=xiph/}
MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/xiph/rav1e
COMMENT=	Fastest and safest AV1 encoder by Xiph
LICENSE=	2-clause-bsd
GITHUB_PROJECT=	rav1e
GITHUB_TAG=	v${PKGVERSION_NOREV}

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
TOOL_DEPENDS+=	nasm>=2.14:../../devel/nasm
.endif
TOOL_DEPENDS+=	cargo-c-[0-9]*:../../devel/cargo-c
TOOL_DEPENDS+=	cbindgen-[0-9]*:../../devel/cbindgen

USE_TOOLS+=	pkg-config

# Require libgit2-1.5
#RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libgit2}/lib
#MAKE_ENV+=	LD_LIBRARY_PATH=${BUILDLINK_PREFIX.libgit2}/lib

.include "cargo-depends.mk"

CARGOC_ARGS=		--verbose --verbose \
			--release \
			--destdir ${DESTDIR} \
			--prefix ${PREFIX}

do-build:
	${RUN} cd ${CARGO_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PREFIX}/bin/cargo-cbuild \
			cbuild \
			${CARGOC_ARGS}

do-install:
	${RUN} cd ${CARGO_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PREFIX}/bin/cargo-cinstall \
			cinstall \
			${CARGOC_ARGS}

# Require libgit2-1.5
#.include "../../devel/libgit2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
