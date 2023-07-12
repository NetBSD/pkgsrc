# $NetBSD: Makefile,v 1.1 2023/07/12 19:34:39 vins Exp $

DISTNAME=	mirmake_20141220.orig
PKGNAME=	mirmake-20141220
CATEGORIES=	devel
MASTER_SITES=	http://www.mirbsd.org/MirOS/dist/mir/make/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	http://www.mirbsd.org/man1/make.htm
COMMENT=	Portable version of MirBSD make(1) and associated tools
LICENSE=	modified-bsd AND isc AND miros

MKSH_BINPATHS=	/bin /usr/bin /usr/local/bin /sfw/bin /opt/local/bin

.for path in ${MKSH_BINPATHS}

## Do not require mksh. May cause edge-case issues.
# .  if exists(${path}/ksh)
# MKSH=		${path}/ksh

.  if exists(${path}/mksh)
MKSH=		${path}/mksh
.  else
TOOL_DEPENDS+=	mksh-[0-9]*:../../shells/mksh
MKSH=		${PREFIX}/bin/mksh
.  endif
.endfor

UID=	`id -un`
GID=	`id -gn`

REPLACE_INTERPRETER+=	mksh
REPLACE.mksh.old=	.*/bin/env mksh
REPLACE.mksh.new=	${MKSH}
REPLACE_FILES.mksh+=	dist/src/usr.bin/mmkdep/mmkdep.sh

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Build.sh
SUBST_VARS.paths=	PREFIX
SUBST_MESSAGE.paths=	Include pkgsrc PREFIX in searched paths.

SUBST_CLASSES+=		bins
SUBST_STAGE.bins=	pre-configure
SUBST_FILES.bins=	dist/scripts/Build.sh dist/scripts/Copy.sh	\
			dist/scripts/sys.mk.ed dist/src/share/mk/sys.mk	\
			dist/src/share/mk/bsd.lib.mk
.for i in lndir lorder mkdep tsort
SUBST_FILES.bins+=	dist/src/usr.bin/m${i}/*
.endfor
SUBST_MESSAGE.bins=	Resolving conflicts with native tools
SUBST_SED.bins+=	-e 's|binstall|minstall|g'
SUBST_SED.bins+=	-e 's|lndir|mlndir|g'
SUBST_SED.bins+=	-e 's|lorder|mlorder|g'
SUBST_SED.bins+=	-e 's|mkdep|mmkdep|g'
SUBST_SED.bins+=	-e 's|tsort|mtsort|g'

.include "../../mk/bsd.prefs.mk"

# build script accepts a number of arguments
BUILD_ARGS=	${OPSYS}
BUILD_ARGS+=	${PREFIX}
BUILD_ARGS+=	${PKGMANDIR}/man
BUILD_ARGS+=	mbmake
BUILD_ARGS+=	""
BUILD_ARGS+=	""
BUILD_ARGS+=	""
BUILD_ARGS+=	${MKSH}
BUILD_ARGS+=	${UID}:${GID}

WRKSRC=		${WRKDIR}/mirmake

MAKE_ENV+=	LIBS=${LIBS:Q}
MAKE_ENV+=	OVERRIDE_MKSH=${MKSH}

post-extract:
	${RUN}cd ${WRKSRC}/dist/src/usr.bin &&		\
		for i in lndir tsort;  do		\
			${MV} $$i/$$i.c $$i/m$$i.c;	\
			${MV} $$i/$$i.1 $$i/m$$i.1;	\
			${MV} $$i m$$i;			\
	done && \
		for i in lorder mkdep ;  do		\
			${MV} $$i/$$i.sh $$i/m$$i.sh;	\
			${MV} $$i/$$i.1 $$i/m$$i.1;	\
			${MV} $$i m$$i;			\
	done
	${RUN}cd ${WRKSRC}/dist/scripts &&		\
		${MV} mkdep.sh.ed mmkdep.sh.ed

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}			\
		${SH} ${WRKSRC}/Build.sh ${BUILD_ARGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV}	\
		${SH} ${WRKSRC}/Install.sh

.if ${OPSYS} == "Linux"
.  include "../../devel/libbsd/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
