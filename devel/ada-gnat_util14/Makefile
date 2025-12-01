# $NetBSD: Makefile,v 1.2 2025/12/01 04:52:24 dkazankov Exp $

DISTNAME=	gnat_util-20.0w-20190814-1532A-src
PKGNAME=	ada-gnat_util14-14.3.0
CATEGORIES=	devel
MASTER_SITES=	https://community.download.adacore.com/v1/26bd253101b46706f5f8e3d0ca8b3107cde99e99?filename=
DISTFILES=	${DEFAULT_DISTFILES}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gnat-community-archives
COMMENT=	Library uniting a number of GNAT sources
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	ada

USE_TOOLS+=	gmake

GCC_DISTNAME=	gcc-${PKGVERSION_NOREV}
DISTFILES+=	${GCC_DISTNAME}.tar.xz
MASTER_SITES+=	${MASTER_SITE_GNU:=gcc/${GCC_DISTNAME}/}

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

SUBST_CLASSES+=		version
SUBST_MESSAGE.version=	Set version in ${SUBST_FILES.version}
SUBST_STAGE.version=	post-extract
SUBST_FILES.version=	gnatvsn.ads
SUBST_SED.version=	-e "s,\"20.0w (20190814)\",\"14.3.0 (20250523)\","
SUBST_SED.version+=	-e "s,\"20.20190814\",\"14.3.0\","
SUBST_SED.version+=	-e "s,\"2019\",\"2025\","
SUBST_SED.version+=	-e "s,:= Gnatpro;,:= FSF;,"

post-extract:
# Rename old sources to prevent participation in build process
	for f in stand.adb tree_in.adb tree_in.ads tree_io.adb tree_io.ads; do \
	    ${MV} ${WRKSRC}/$$f ${WRKSRC}/$$f.orig; \
	done

pre-configure:
# Update GNAT sources
	for f in $$(cat ${WRKSRC}/MANIFEST.gnat_util); do \
	    ${CP} ${WRKDIR}/${GCC_DISTNAME}/gcc/ada/$$f ${WRKSRC}; \
	done

MAKE_FLAGS+=	prefix=${DESTDIR}${GNAT_PREFIX}

PLIST_VARS+=			shlibs

USE_PKGSRC_GCC_RUNTIME?=	no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=			yes
MAKE_FLAGS+=			ENABLE_SHARED=yes
.else
MAKE_FLAGS+=			ENABLE_SHARED=no
.endif

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/relocatable\/|static-pic\/|lib\/.*\.so.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
