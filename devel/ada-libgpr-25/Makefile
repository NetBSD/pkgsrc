# $NetBSD: Makefile,v 1.3 2025/09/04 08:15:53 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	libgpr-${GNAT_NAME}-25.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gprbuild
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gprbuild
COMMENT=	LIBGPR development libraries, release 25
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
HAS_CONFIGURE=	yes

USE_LANGUAGES=	c ada

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

SUBST_CLASSES+=		version
SUBST_MESSAGE.version=	Replace version,date and type in ${SUBST_FILES.version}
SUBST_STAGE.version=	post-extract
SUBST_FILES.version=	gpr/src/gpr-version.ads
SUBST_SED.version=	-e "s,18.0w,25.0w,"
SUBST_SED.version+=	-e "s,19940713,20241126,"
SUBST_SED.version+=	-e "s,\"2016\",\"2024\","
SUBST_SED.version+=	-e "s,= Gnatpro;,= FSF;,"

# Use C preprocessed symbols on NetBSD
.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=			getrusage
SUBST_MESSAGE.getrusage=	Replace getrusage with __netbsd_getrusage in ${SUBST_FILES.getrusage}
SUBST_STAGE.getrusage=		post-extract
SUBST_FILES.getrusage=		gpr/src/gpr-util-put_resource_usage__unix.adb
SUBST_SED.getrusage=		-e "s,with Import\, Convention => C;,with Import\, Convention => C\, External_Name => \"__netbsd_getrusage\";,"
.endif

CONFIG_SHELL=		${MAKE_PROGRAM} -f
CONFIGURE_SCRIPT=	${WRKSRC}/Makefile
CONFIGURE_ARGS=		setup

CONFIGURE_ARGS+=		prefix=${DESTDIR}${GNAT_PREFIX}

PLIST_VARS+=			shlibs

USE_PKGSRC_GCC_RUNTIME?=	no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=			yes
CONFIGURE_ARGS+=		ENABLE_SHARED=yes
BUILDLINK_DEPMETHOD.xmlada-25=	full
.else
CONFIGURE_ARGS+=		ENABLE_SHARED=no
.endif

BUILD_TARGET=			libgpr.build
INSTALL_TARGET=			libgpr.install

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/\.relocatable\/|\/relocatable\/|\.static-pic\/|\/static-pic\/|lib\/.*\.so.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"
.include "../../textproc/ada-xmlada-25/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
