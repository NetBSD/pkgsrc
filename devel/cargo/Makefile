# $NetBSD: Makefile,v 1.1 2017/09/13 00:12:54 ryoon Exp $

CARGO_VER=	0.17.0
RUST_VER=	1.16.0
PKGNAME=	cargo-${CARGO_VER}
CATEGORIES=	lang
MASTER_SITES=	http://static.rust-lang.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://crates.io/
COMMENT=	Package manager for Rust langage
LICENSE=	mit OR apache-2.0

DIST_SUBDIR=	cargo

# For crates download, Accept: header is required.
# See: https://github.com/rust-lang/crates.io/issues/466
FETCH_USING=	custom
FETCH_CMD=	 ${TOOLS_PATH.curl}
FETCH_BEFORE_ARGS=	--fail --insecure --location --remote-time -H 'Accept:'
FETCH_OUTPUT_ARGS=	-o
FETCH_AFTER_ARGS=	-O

CARGODIST=	cargo-0.17.0
CARGODISTFILE=	cargo-0.17.0.tar.gz
SITES.${CARGODISTFILE}=	-https://github.com/rust-lang/cargo/archive/0.17.0.tar.gz
CARGO_DISTFILES=	${CARGODISTFILE}

.include "crates.mk"

DISTFILES=	${CARGO_DISTFILES} rustc-${RUST_VER}-src.tar.gz

WRKSRC=		${WRKDIR}/${CARGODIST}

DEPENDS+=	rust-[0-9]*:../../lang/rust

MAKE_ENV+=	RUSTFLAGS="-Clink-arg=${COMPILER_RPATH_FLAG}${PREFIX}/lib"

USE_TOOLS+=		curl gmake perl pkg-config

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--build=${CARGO_ARCH}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--release-channel=stable
CONFIGURE_ARGS+=	--cargo=${WRKDIR}/cargo-nightly-${CARGO_ARCH}/cargo/bin/cargo
CONFIGURE_ARGS+=	--rustc=${PREFIX}/bin/rustc
CONFIGURE_ARGS+=	--rustdoc=${PREFIX}/bin/rustdoc
MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}
MAKE_ENV+=		LIBGIT2_SYS_USE_PKG_CONFIG=1
MAKE_ENV+=		VERBOSE=1

.include "../../mk/bsd.prefs.mk"

#BUILDLINK_TRANSFORM.NetBSD+=	rm:-Wl,--enable-new-dtags

CARGO_STAGE0_VER=	0.16.0
.if !empty(MACHINE_PLATFORM:MDarwin-*-i386) || make(distinfo) || make (makesum) || make(mdi)
CARGO_ARCH:=		i686-apple-darwin
CARGO_STAGE0:=		cargo-${CARGO_STAGE0_VER}-${CARGO_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${CARGO_STAGE0}
.endif
.if !empty(MACHINE_PLATFORM:MDarwin-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
CARGO_ARCH:=		x86_64-apple-darwin
CARGO_STAGE0:=		cargo-${CARGO_STAGE0_VER}-${CARGO_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${CARGO_STAGE0}
.endif
.if !empty(MACHINE_PLATFORM:MLinux-*-i386) || make(distinfo) || make (makesum) || make(mdi)
CARGO_ARCH:=		i686-unknown-linux-gnu
CARGO_STAGE0:=		cargo-${CARGO_STAGE0_VER}-${CARGO_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${CARGO_STAGE0}
.endif
.if !empty(MACHINE_PLATFORM:MLinux-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
CARGO_ARCH:=		x86_64-unknown-linux-gnu
CARGO_STAGE0:=		cargo-${CARGO_STAGE0_VER}-${CARGO_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${CARGO_STAGE0}
.endif
#.if !empty(MACHINE_PLATFORM:MSunOS-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
#RUST_ARCH:=		x86_64-sun-solaris
#RUST_STAGE0:=		cargo-${CARGO_STAGE0_VER}-${CARGO_ARCH}.tar.gz
#SITES.${RUST_STAGE0}=	https://us-east.manta.joyent.com/pkgsrc/public/pkg-bootstraps/
#DISTFILES:=		${DISTFILES} ${CARGO_STAGE0}
#.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
CARGO_ARCH=		x86_64-unknown-netbsd
CARGO_STAGE0:=		cargo-${CARGO_STAGE0_VER}-${CARGO_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${CARGO_STAGE0}
.endif

.if !defined(CARGO_ARCH)
NOT_FOR_PLATFORM+=	${MACHINE_PLATFORM}
.endif

OPSYSVARS+=		SOEXT
SOEXT.Darwin=		dylib
SOEXT.*=		so

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/rustlib/install.log
	${RM} -f ${DESTDIR}${PREFIX}/lib/rustlib/components
	${RM} -f ${DESTDIR}${PREFIX}/lib/rustlib/rust-installer-version
	${RM} -f ${DESTDIR}${PREFIX}/lib/rustlib/uninstall.sh

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
