# $NetBSD: Makefile,v 1.59 2025/12/17 19:05:30 vins Exp $

DISTNAME=	fish-4.2.1
PKGREVISION=	2
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=fish-shell/}
GITHUB_PROJECT=	fish-shell
GITHUB_RELEASE=	${PKGVERSION_NOREV}
DISTFILES+=	${DEFAULT_DISTFILES} 0.2.9-utf32.tar.gz
SITES.0.2.9-utf32.tar.gz=	${MASTER_SITES}/rust-pcre2/archive/refs/tags/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fishshell.com/
COMMENT=	User friendly command line shell for UNIX-like operating systems
LICENSE=	gnu-gpl-v2

.include "cargo-depends.mk"

VENDORSRC=	${WRKDIR}/vendor
VENDORPATCH=	patch-libc.rs patch-nix.rs

USE_TOOLS+=		msgfmt patch pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	fish.pc.in

EGDIR=		${PREFIX}/share/examples/fish
CONF_FILES=	${EGDIR}/config.fish ${PKG_SYSCONFDIR}/fish/config.fish
OWN_DIRS+=	${PKG_SYSCONFDIR}/fish/functions
OWN_DIRS+=	${PKG_SYSCONFDIR}/fish/conf.d
OWN_DIRS+=	${PKG_SYSCONFDIR}/fish/completions

PKG_SHELL=		bin/fish

REPLACE_PYTHON+=	share/tools/*.py

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_SYSCONFDIR=${PKG_SYSCONFDIR}
CMAKE_CONFIGURE_ARGS+=	-DFISH_USE_SYSTEM_PCRE2=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_GETTEXT=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_DOCS=OFF

RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.pcre2}/lib
RUSTFLAGS+=		-C link-arg=-L${BUILDLINK_PREFIX.pcre2}/lib

PKGSRC_MAKE_ENV+=	FISH_BUILD_VERSION=${PKGVERSION_NOREV} \
			RUSTFLAGS=${RUSTFLAGS:M*:Q}

TEST_TARGET=		fish_run_tests
TEST_DEPENDS+=		${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
TEST_ENV+=		LC_ALL=C.UTF-8		# requires a UTF-8 locale

post-patch:
	@${STEP_MSG} "Patching vendor crates"
.for i in ${VENDORPATCH}
	@${STEP_MSG} "Applying pkgsrc patch ${PATCHDIR}/vendor/${i}"
	${RUN}${CP} ${PATCHDIR}/vendor/${i} ${VENDORSRC}
	${RUN}cd ${VENDORSRC} && \
		${PATCH} -b -p0 < ${VENDORSRC}/${i}
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../lang/python/application.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
