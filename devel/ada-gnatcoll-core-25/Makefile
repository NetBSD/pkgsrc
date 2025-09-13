# $NetBSD: Makefile,v 1.4 2025/09/13 05:25:00 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-${GNAT_NAME}-25.0.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gnatcoll-core
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gnatcoll-core
COMMENT=	The GNAT Components Collection (GNATcoll) - Core packages, release 25
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake grep

USE_LANGUAGES=	c ada

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

# Use C preprocessed symbols on NetBSD
.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		ldl
SUBST_MESSAGE.ldl=	Fix extra libs on NetBSD in ${SUBST_FILES.ldl}
SUBST_STAGE.ldl=	post-extract
SUBST_FILES.ldl=	core/gnatcoll_core.gpr
SUBST_SED.ldl=		-e "s,\"-ldl\",\"\","

SUBST_CLASSES+=		opendir
SUBST_MESSAGE.opendir=	Replace opendir with __gnatcoll_opendir in ${SUBST_FILES.opendir}
SUBST_STAGE.opendir=	post-extract
SUBST_FILES.opendir=	core/src/os/unix/gnatcoll-os-libc-dirent.ads
SUBST_SED.opendir=	-e "s,\"opendir\",\"__gnatcoll_opendir\","
.endif

MAKE_FLAGS+=		PYTHON=${PYTHONBIN:Q} prefix=${DESTDIR}${GNAT_PREFIX} BUILD=PROD

PLIST_VARS+=			shlibs

USE_PKGSRC_GCC_RUNTIME?=	no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=			yes
MAKE_FLAGS+=			ENABLE_SHARED=yes
BUILDLINK_DEPMETHOD.xmlada-25=	full
BUILDLINK_DEPMETHOD.libgpr-25=	full
.else
MAKE_FLAGS+=			ENABLE_SHARED=no
.endif

pre-install:
	${RUN} ${MKDIR} ${DESTDIR}${GNAT_PREFIX}

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/\.relocatable\/|\.static-pic\/|lib\/.*\.so.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"
.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.include "../../devel/ada-libgpr-25/buildlink3.mk"

.include "../../lang/python/tool.mk"

.include "../../mk/bsd.pkg.mk"
