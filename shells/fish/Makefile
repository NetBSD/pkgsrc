# $NetBSD: Makefile,v 1.64 2026/05/10 18:46:48 vins Exp $

DISTNAME=	fish-4.7.1
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

USE_TOOLS+=		msgfmt patch pkg-config pax
USE_PKGLOCALEDIR=	yes

TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

PKGCONFIG_OVERRIDE+=	fish.pc.in

EGDIR=		${PREFIX}/share/examples/fish
CONF_FILES=	${EGDIR}/config.fish ${PKG_SYSCONFDIR}/fish/config.fish
OWN_DIRS+=	${PKG_SYSCONFDIR}/fish/functions
OWN_DIRS+=	${PKG_SYSCONFDIR}/fish/conf.d
OWN_DIRS+=	${PKG_SYSCONFDIR}/fish/completions

PKG_SHELL=		bin/fish

REPLACE_PYTHON+=	share/tools/*.py

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_SYSCONFDIR=${PKG_SYSCONFDIR}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/${PKGMANDIR}
# Disable dynamic linking with pcre2 to prevent missing shared objects.
# See https://mail-index.netbsd.org/tech-pkg/2025/12/15/msg031761.html
CMAKE_CONFIGURE_ARGS+=	-DFISH_USE_SYSTEM_PCRE2=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_MESSAGE_LOCALIZATION=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_DOCS=ON
CMAKE_CONFIGURE_ARGS+=	-DSPHINX_EXECUTABLE=${PREFIX}/bin/sphinx-build-${PYVERSSUFFIX}

RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.pcre2}/lib
RUSTFLAGS+=		-C link-arg=-L${BUILDLINK_PREFIX.pcre2}/lib

PKGSRC_MAKE_ENV+=	FISH_BUILD_VERSION=${PKGVERSION_NOREV}

TEST_TARGET=		fish_run_tests
TEST_DEPENDS+=		${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
TEST_ENV+=		LC_ALL=C.UTF-8		# requires a UTF-8 locale

post-install:
	cd ${WRKSRC}/share/themes && ${PAX} -wr * \
		${DESTDIR}/${PREFIX}/share/themes
	cd ${WRKSRC}/share/prompts && ${PAX} -wr * \
		${DESTDIR}/${PREFIX}/share/prompts

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../lang/python/application.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
