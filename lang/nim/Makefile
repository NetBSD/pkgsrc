# $NetBSD: Makefile,v 1.40 2026/11/17 15:00:37 wiz Exp $

# Nim is quite a weird language to package, meaning that the official packaging
# guideline recommends using a tarball that is created via a CI and also
# because the bootstrap script uses git to clone some submodules. It however
# seems that both of those weridinesses can be bypassed, for once because
# just downloading the nim from the homepage is the same version as the one
# that the CI created (checksums matched) and the git clone only happens if
# the submodules are not already present. Because of this, we pull not only
# the nim tarball but also the ones for:
#
# - Atlas (Package cloner, that manages project dependencies in an isolated
#		deps/ directory)
# - sat (SAT solver written in nim)
#
# When taking a look at `koch.nim` in the source tree of nim, we can see, that
# these packages are not pinned to a version but rather a commit hash. We do
# the same with the `*_TAG` variables. Afterwards we add the needed
# `*_DISTFILE`'s to the distfiles and extract them into the root. Furthermore
# we then move the extracted folders to the correct location in `post-extract`.
#
# Helpful sources:
# - https://nim-lang.github.io/Nim/packaging.html
# - `koch.nim` in the source tree

DISTNAME=	nim-2.4.2
CATEGORIES=	lang
MASTER_SITES=	http://nim-lang.org/download/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nim-lang.org/
COMMENT=	The Nim programming language
LICENSE=	mit

GH_SFX=			.tar.gz

EXTRACT_DIR.${SAT_DISTFILE}=		${WRKSRC}
EXTRACT_DIR.${NIMBLE_DISTFILE}=		${WRKSRC}

# https://github.com/nim-lang/Nim/blob/devel/koch.nim
GITHUB_SUBMODULES+=	nim-lang atlas fa19ace5c5d176d0e19f9b6ad08239ce2ceea676 dist/atlas
GITHUB_SUBMODULES+=	nim-lang nimble 302a71139254b43b1488d65de111b6734d1a7490 dist/nimble
GITHUB_SUBMODULES+=	nim-lang sat 9d52513b3c68bfb929dbd687d4fb2836cfee6936 dist/atlas/dist/sat

# https://github.com/nim-lang/nimble/tree/master/vendor
GITHUB_SUBMODULES+=	status-im nim-bearssl 38a5622be728fb083f6fe55c124502995b2f4e3d dist/nimble/vendor/bearssl
GITHUB_SUBMODULES+=	nim-lang checksums f8f6bd34bfa3fe12c64b919059ad856a96efcba0 dist/nimble/vendor/checksums
GITHUB_SUBMODULES+=	status-im nim-chronos dcd20011df38c0cb603382f3d626471de71d19df dist/nimble/vendor/chronos
GITHUB_SUBMODULES+=	status-im nim-http-utils f142cb2e8bd812dd002a6493b6082827bb248592 dist/nimble/vendor/httputils
GITHUB_SUBMODULES+=	arnetheduck nim-results b319652e98a198fa881ca70a76754c2dd6f09804 dist/nimble/vendor/results
GITHUB_SUBMODULES+=	nim-lang sat e63eaea8baf00bed8bcd5a29ffd8823abb265b39 dist/nimble/vendor/sat
GITHUB_SUBMODULES+=	status-im nim-stew 83eb1157963b7f49351dbdd858355fa990bbe23c dist/nimble/vendor/stew
GITHUB_SUBMODULES+=	guzba zippy bcb8c1e1be6abb0a0e35a3c6040cdd9391cc993f dist/nimble/vendor/zippy

DEPENDS+=	coreutils-[0-9]*:../../sysutils/coreutils

USE_TOOLS+=	bash gmake
REPLACE_BASH+=	bin/nim-gdb

USE_LANGUAGES=	c

# SUBST_CLASSES+=		paths
# SUBST_STAGE.paths=	pre-configure
# SUBST_FILES.paths=	config/nim.cfg
# SUBST_SED.paths=	-e 's,/usr/pkg,${PREFIX},g'

# Nim doesn't automatically passes LDFLAGS/CFLAGS variables to the compiler
# but rather uses its own --passL/--passC flags. The two lines below translate
# the flags so the nim compiler actually uses them.
NIM_FLAGS=	${LDFLAGS:S/^/--passL:/}
NIM_FLAGS+=	${CFLAGS:S/^/--passC:/}

INSTALLATION_DIRS+=	bin

post-extract:
	# TODO: csources for cross-building?
	# ${MV} ${WRKSRC}/csources_v2-${C2VERSION_TAG} ${WRKSRC}/csources_v2

do-build:
	cd ${WRKSRC} && ${GMAKE}

	# build koch
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./bin/nim c \
		-d:release \
		--parallelBuild:${_MAKE_JOBS_N} \
		koch

	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./koch \
		boot \
		-d:release \
		--parallelBuild:${_MAKE_JOBS_N} \
		${NIM_FLAGS}

	# Build tools
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./koch \
		tools \
		-d:release \
		--parallelBuild:${_MAKE_JOBS_N} \
		${NIM_FLAGS}


# The test suite will fail, however it may work in the future. For now, this
# is commented out.
# do-test:
#	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./koch \
#		tests \
#		--pedantic \
#		--targets="c js" \
#		all


do-install:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./install.sh \
		${DESTDIR}${PREFIX}

.for fn in nim nimble nimsuggest nimgrep
	${LN} -sf ${DESTDIR}${PREFIX}/nim/bin/${fn} ${DESTDIR}${PREFIX}/bin/${fn}
.endfor

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
