# $NetBSD: Makefile,v 1.39 2026/11/11 11:54:14 wiz Exp $

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

DISTNAME=	nim-2.4.0
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://nim-lang.org/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nim-lang.org/
COMMENT=	The Nim programming language
LICENSE=	mit

ATLAS_TAG=	aa6fb162006f3015aa84c4305e15cb4d230f5ad6
SAT_TAG=	9d52513b3c68bfb929dbd687d4fb2836cfee6936

GH_SFX=		.tar.gz

ATLAS_DISTNAME=	atlas-${ATLAS_TAG}
SAT_DISTNAME=	sat-${SAT_TAG}

ATLAS_DISTFILE=	${ATLAS_DISTNAME}${GH_SFX}
SAT_DISTFILE=	${SAT_DISTNAME}${GH_SFX}

DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		${ATLAS_DISTFILE}
DISTFILES+=		${SAT_DISTFILE}

SITES.${ATLAS_DISTFILE}=	-${MASTER_SITE_GITHUB:=nim-lang/atlas/archive/}${ATLAS_TAG}${GH_SFX}
SITES.${SAT_DISTFILE}=		-${MASTER_SITE_GITHUB:=nim-lang/sat/archive/}${SAT_TAG}${GH_SFX}

EXTRACT_DIR.${ATLAS_DISTFILE}=	${WRKSRC}
EXTRACT_DIR.${SAT_DISTFILE}=	${WRKSRC}

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

	${MKDIR} ${WRKSRC}/dist
	${MV} ${WRKSRC}/atlas-${ATLAS_TAG} ${WRKSRC}/dist/atlas

	${MKDIR} ${WRKSRC}/dist/atlas/dist
	${MV} ${WRKSRC}/sat-${SAT_TAG} ${WRKSRC}/dist/atlas/dist/sat


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
