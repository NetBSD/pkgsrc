# $NetBSD: Makefile,v 1.1 2025/07/10 12:35:21 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-${GNAT_NAME}-24.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gnatcoll-core
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gnatcoll-core
COMMENT=	The GNAT Components Collection (GNATcoll) - Core packages, release 24
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake grep

USE_LANGUAGES=	c ada

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	13

SUBST_CLASSES+=		fixver
SUBST_STAGE.fixver=	pre-configure
SUBST_FILES.fixver=	version_information
SUBST_MESSAGE.fixver=	Fix version in ${SUBST_FILES.fixver}
SUBST_SED.fixver=	-e 's,0.0,24.0w,g'

# Use C preprocessed symbols on NetBSD
.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		ldl
SUBST_MESSAGE.ldl=	Fix extra libs on NetBSD in ${SUBST_FILES.ldl}
SUBST_STAGE.ldl=	pre-configure
SUBST_FILES.ldl=	gnatcoll.gpr
SUBST_SED.ldl=		-e "s,\"-ldl\",\"\","

SUBST_CLASSES+=		opendir
SUBST_MESSAGE.opendir=	Replace opendir with __gnatcoll_opendir in ${SUBST_FILES.opendir}
SUBST_STAGE.opendir=	pre-configure
SUBST_FILES.opendir=	src/os/unix/gnatcoll-os-libc-dirent.ads
SUBST_SED.opendir=	-e "s,\"opendir\",\"__gnatcoll_opendir\","
.endif

MAKE_FLAGS+=	prefix=${DESTDIR}${GNAT_PREFIX} BUILD=PROD

PLIST_VARS+=			shlibs

USE_PKGSRC_GCC_RUNTIME?=	no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=			yes
MAKE_FLAGS+=			ENABLE_SHARED=yes
BUILDLINK_DEPMETHOD.xmlada-24=	full
BUILDLINK_DEPMETHOD.libgpr-24=	full
.else
MAKE_FLAGS+=			ENABLE_SHARED=no
.endif

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/\.relocatable\/|\.static-pic\/|lib\/.*\.so.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"
.include "../../textproc/ada-xmlada-24/buildlink3.mk"
.include "../../devel/ada-libgpr-24/buildlink3.mk"

#.include "../../lang/python/tool.mk"

.include "../../mk/bsd.pkg.mk"
