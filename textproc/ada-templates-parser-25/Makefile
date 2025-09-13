# $NetBSD: Makefile,v 1.2 2025/09/13 12:06:11 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-${GNAT_NAME}-25.0.0
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	templates-parser
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/templates-parser
COMMENT=	Tools to create templated text streams, such as dynamic HTML documents
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

USE_LANGUAGES=	c ada # really ada only

HAS_CONFIGURE=	yes

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

SUBST_CLASSES+=		version
SUBST_MESSAGE.version=	Fix version number in ${SUBST_FILES.version}
SUBST_STAGE.version=	post-extract
SUBST_FILES.version=	Makefile
SUBST_SED.version=	-e "s,22.0,25.0,"

CONFIG_SHELL=		${MAKE_PROGRAM}
CONFIGURE_SCRIPT=	setup
CONFIGURE_ARGS=		VERSION=25.0 prefix=${GNAT_PREFIX}

PLIST_VARS+=		shlibs

USE_PKGSRC_GCC_RUNTIME?=	no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=			yes
CONFIGURE_ARGS+=		ENABLE_SHARED=true
BUILDLINK_DEPMETHOD.xmlada-25=	full
.else
CONFIGURE_ARGS+=		ENABLE_SHARED=false
.endif

BUILD_TARGET=		build
BUILD_MAKE_FLAGS+=	GPROPTS=${GPRBUILD_OPTIONS:Q}

CHECK_PIE_SKIP+=	${GNAT_PKGBASE}/bin/*

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/\.relocatable\/|\.static-pic\/|lib\/.*\.${SHLIB_EXT}.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../textproc/ada-xmlada-25/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
