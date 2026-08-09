# $NetBSD: Makefile,v 1.68 2026/08/09 16:45:24 wiz Exp $

DISTNAME=	fish-4.8.1
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=fish-shell/}
GITHUB_PROJECT=	fish-shell
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fishshell.com/
COMMENT=	User friendly command line shell for UNIX-like operating systems
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
RUST_PCRE2_REV=		0.2.9-utf32
FLUENT_RS_REV=		cf712bced280b217b6307edabc2089b3e57204ab
FLUENT_FTL_TOOLS_REV=	5917664c8f2e4928ef1e480ff5c13bbe1e226066
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		rust-pcre2-${RUST_PCRE2_REV}.tar.gz
DISTFILES+=		fluent-rs-${FLUENT_RS_REV}.tar.gz
DISTFILES+=		fluent-ftl-tools-${FLUENT_FTL_TOOLS_REV}.tar.gz

SITES.rust-pcre2-${RUST_PCRE2_REV}.tar.gz+=		-${MASTER_SITE_GITHUB:=fish-shell/}rust-pcre2/archive/refs/tags/${RUST_PCRE2_REV}.tar.gz
SITES.fluent-rs-${FLUENT_RS_REV}.tar.gz+=		-${MASTER_SITE_GITHUB:=danielrainer/}fluent-rs/archive/refs/${FLUENT_RS_REV}.tar.gz
SITES.fluent-ftl-tools-${FLUENT_FTL_TOOLS_REV}.tar.gz+=	-https://codeberg.org/danielrainer/fluent-ftl-tools/archive/${FLUENT_FTL_TOOLS_REV}.tar.gz

.include "cargo-depends.mk"

USE_TOOLS+=		patch pkg-config pax

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

PKGSRC_MAKE_ENV+=	FISH_BUILD_VERSION=${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	share/prompts
INSTALLATION_DIRS+=	share/themes

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	mac notmac
.if ${OPSYS} == "Darwin"
PLIST.mac=	yes
.else
PLIST.notmac=	yes
.endif

TEST_TARGET=		fish_run_tests
TEST_ENV+=		LC_ALL=C.UTF-8		# requires a UTF-8 locale
# test status as of 4.8.1
# 230 / 238 passed (12 skipped)

post-install:
	cd ${WRKSRC}/share/themes && ${PAX} -wr * \
		${DESTDIR}/${PREFIX}/share/themes
	cd ${WRKSRC}/share/prompts && ${PAX} -wr * \
		${DESTDIR}/${PREFIX}/share/prompts

.include "../../lang/python/tool.mk"
.include "../../devel/cmake/build.mk"
.include "../../lang/python/application.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
