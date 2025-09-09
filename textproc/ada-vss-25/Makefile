# $NetBSD: Makefile,v 1.2 2025/09/09 07:25:12 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	vss-${GNAT_NAME}-25.0.0
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	VSS
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/VSS
COMMENT=	VSS - high level string and text processing library
LICENSE=	apache-2.0

USE_TOOLS+=	gmake

USE_LANGUAGES=	ada

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

PLIST_VARS+=			shlibs

USE_PKGSRC_GCC_RUNTIME?=	no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=			yes
BUILD_TARGET=			build-all-libs
INSTALL_TARGET=			install-all-libs
BUILDLINK_DEPMETHOD.xmlada-25=	full
.else
BUILD_TARGET=			build-libs-static
INSTALL_TARGET=			install-libs-static
.endif

MAKE_FLAGS=			PREFIX=${GNAT_PREFIX}
GPRFLAGS=			${GPRBUILD_OPTIONS}
BUILD_MAKE_FLAGS+=		BUILD_PROFILE=release GPRFLAGS=${GPRFLAGS:Q}

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/\/relocatable\/|\/static-pic\/|lib\/.*\.so.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../textproc/ada-xmlada-25/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
