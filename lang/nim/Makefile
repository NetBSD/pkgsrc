# $NetBSD: Makefile,v 1.37 2024/05/16 09:59:20 pho Exp $

DISTNAME=	nim-2.0.4
CATEGORIES=	lang
MASTER_SITES=	http://nim-lang.org/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nim-lang.org/
COMMENT=	The Nim programming language
LICENSE=	mit

# C2VERSION_TAG=	86742fb02c6606ab01a532a0085784effb2e753e
# NIMBLE_TAG=	168416290e49023894fc26106799d6f1fc964a2d
# CHECKSUMS_TAG=	b4c73320253f78e3a265aec6d9e8feb83f97c77b
ATLAS_TAG=	7b780811a168f3f32bff4822369dda46a7f87f9a

GH_SFX=		.tar.gz

# C2VERSION_DISTNAME=	c2version-${C2VERSION_TAG}
# NIMBLE_DISTNAME=	nimble-${NIMBLE_TAG}
# CHECKSUMS_DISTNAME=	checksums-${CHECKSUMS_TAG}
ATLAS_DISTNAME=		atlas-${ATLAS_TAG}

# C2VERSION_DISTFILE=	${C2VERSION_DISTNAME}${GH_SFX}
# NIMBLE_DISTFILE=	${NIMBLE_DISTNAME}${GH_SFX}
# CHECKSUMS_DISTFILE=	${CHECKSUMS_DISTNAME}${GH_SFX}
ATLAS_DISTFILE=		${ATLAS_DISTNAME}${GH_SFX}

DISTFILES=		${DEFAULT_DISTFILES}
# DISTFILES+=		${C2VERSION_DISTFILE}
# DISTFILES+=		${NIMBLE_DISTFILE}
# DISTFILES+=		${CHECKSUMS_DISTFILE}
DISTFILES+=		${ATLAS_DISTFILE}

# SITES.${C2VERSION_DISTFILE}=	-${MASTER_SITE_GITHUB:=nim-lang/csources_v2/archive/}${C2VERSION_TAG}${GH_SFX}
# SITES.${NIMBLE_DISTFILE}=	-${MASTER_SITE_GITHUB:=nim-lang/nimble/archive/}${NIMBLE_TAG}${GH_SFX}
# SITES.${CHECKSUMS_DISTFILE}=	-${MASTER_SITE_GITHUB:=nim-lang/checksums/archive/}${CHECKSUMS_TAG}${GH_SFX}
SITES.${ATLAS_DISTFILE}=	-${MASTER_SITE_GITHUB:=nim-lang/atlas/archive/}${ATLAS_TAG}${GH_SFX}

# EXTRACT_DIR.${C2VERSION_DISTFILE}=	${WRKSRC}/
# EXTRACT_DIR.${NIMBLE_DISTFILE}=		${WRKSRC}/dist/
# EXTRACT_DIR.${CHECKSUMS_DISTFILE}=	${WRKSRC}/dist/
EXTRACT_DIR.${ATLAS_DISTFILE}=		${WRKSRC}/dist/

#
# Support NetBSD/aarch64:
#     https://github.com/nim-lang/Nim/pull/23616
#
# Please remove this block once the upstream merges it. Also remove
# nim-2.0.4+netbsd-aarch64.tar.xz from our LOCAL_PORTS; it is a tarball of
# updated csources that support this platform.
#
.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_PLATFORM:MNetBSD-*-aarch64} || make(distinfo) || make(makesum) || make(mdi)
NBAARCH64_DISTFILE=			nim-2.0.4+netbsd-aarch64.tar.xz
DISTFILES+=				${NBAARCH64_DISTFILE}
SITES.${NBAARCH64_DISTFILE}=		${MASTER_SITE_LOCAL}
EXTRACT_DIR.${NBAARCH64_DISTFILE}=	${WRKSRC}/
.endif
#

DEPENDS+=	coreutils-[0-9]*:../../sysutils/coreutils

USE_TOOLS+=	bash pax
REPLACE_BASH+=	bin/nim-gdb

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	lib/nim/tools/debug
INSTALLATION_DIRS+=	share/nimble/pkgs/nim-${PKGVERSION_NOREV}/dist/checksums
INSTALLATION_DIRS+=	share/nim
INSTALLATION_DIRS+=	include
INSTALLATION_DIRS+=	lib/nim/nimsuggest
INSTALLATION_DIRS+=	lib/nim/nimpretty

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	config/nim.cfg
SUBST_SED.paths=	-e 's,/usr/pkg,${PREFIX},g'

post-extract:
	# TODO: csources for cross-building?
	# ${MV} ${WRKSRC}/csources_v2-${C2VERSION_TAG} ${WRKSRC}/csources_v2
	${MKDIR} ${WRKSRC}/dist
	# ${MV} nimble-$_nimbleversion $build_wrksrc/dist/nimble
	#mv checksums-$_checksumsversion $build_wrksrc/dist/checksums
	#mkdir -p $build_wrksrc/dist/nimble/dist
	#cp -r $build_wrksrc/dist/checksums $build_wrksrc/dist/nimble/dist/checksums
	${MV} ${WRKSRC}/dist/atlas-${ATLAS_TAG} ${WRKSRC}/dist/atlas

# nim doesn't honor the environment variable LDFLAGS. In order to
# support PKGSRC_USE_RELRO, we need to translate the flags to compiler
# options.
NIM_FLAGS=	${LDFLAGS:S/^/--passL:/}
do-build:
	# build nim csource
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} sh ./build.sh
	printf '#! %s\nexec %s _=%s/nim/bin/nim %s/nim/bin/nim "$$@"\n' \
		"${SH}" "${SETENV}" "${PREFIX}" "${PREFIX}" \
		> ${WRKSRC}/nim-wrapper.sh
	# build koch
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./bin/nim c --skipUserCfg --skipParentCfg --parallelBuild:${_MAKE_JOBS_N} koch
	# build nim
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./koch boot --parallelBuild:${_MAKE_JOBS_N} -d:release ${NIM_FLAGS}
	# build tools
	# TODO: build the 'external' tools, in separate packages
	# cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./koch --stable toolsNoExternal --parallelBuild:${_MAKE_JOBS_N} ${NIM_FLAGS}
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./koch --stable tools --parallelBuild:${_MAKE_JOBS_N} ${NIM_FLAGS}
	# build niminst
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./bin/nim compile -d:release --parallelBuild:${_MAKE_JOBS_N} ${NIM_FLAGS} tools/niminst/niminst.nim

do-install:
	cd ${WRKSRC} && sh ./install.sh ${DESTDIR}${PREFIX}
	cd ${WRKSRC}/bin && ${PAX} -r -w . ${DESTDIR}${PREFIX}/nim/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/nim-wrapper.sh ${DESTDIR}${PREFIX}/bin/nim
	${RM} ${DESTDIR}${PREFIX}/nim/bin/nim-gdb.orig
	${INSTALL} ${WRKSRC}/tools/niminst/niminst ${DESTDIR}${PREFIX}/nim/bin/
.for x in nim-gdb nim_dbg nimgrep niminst nimpretty nimsuggest testament
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -sf ${DESTDIR}${PREFIX}/nim/bin/${x} ${x}
.endfor
	cd ${WRKSRC}/tools/debug/ && ${PAX} -r -w . ${DESTDIR}${PREFIX}/lib/nim/tools/debug/

	# This is imported from share/nimble/pkgs/nim-*/compiler/nimblecmd.nim.
	cd ${WRKSRC}/dist/checksums/ && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/nimble/pkgs/nim-${PKGVERSION_NOREV}/dist/checksums/
.for d in nimsuggest nimpretty
	cd ${WRKSRC}/${d} && ${PAX} -r -w . ${DESTDIR}${PREFIX}/lib/nim/${d}/
	${LN} -sf ${DESTDIR}${PREFIX}/lib/nim/${d} ${DESTDIR}${PREFIX}/share/nim/${d}
.endfor

do-test:
	cd ${WRKSRC} && ./bin/nim compile koch.nim
	cd ${WRKSRC} && LD_LIBRARY_PATH=${PREFIX}/lib ./koch test all --parallelBuild:${_MAKE_JOBS_N}

.include "../../mk/bsd.pkg.mk"
