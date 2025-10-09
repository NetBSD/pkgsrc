# $NetBSD: Makefile,v 1.2 2025/10/09 19:50:11 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${GNAT_NAME}-${GITHUB_TAG}.0
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gnatcoll-db
GITHUB_TAG=	25.2

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gnatcoll-db
COMMENT=	The GNAT Components Collection (GNATcoll) - Database packages
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake grep

HAS_CONFIGURE=		yes

CHECK_PIE_SKIP+=	${GNAT_PKGBASE}/bin/*

USE_LANGUAGES=		c ada

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

.include "options.mk"

SUBST_CLASSES+=		fixver
SUBST_STAGE.fixver=	pre-configure
SUBST_FILES.fixver=	version_information
SUBST_SED.fixver=	-e 's,0.0,${GITHUB_TAG},g'
SUBST_MESSAGE.fixver=	Fix version information

CONFIG_SHELL=		${MAKE_PROGRAM}
CONFIGURE_SCRIPT=	setup

CONFIGURE_ARGS+=	prefix=${DESTDIR}${GNAT_PREFIX} BUILD=PROD BUILD_DIRS=${PKG_BUILD_DIRS:Q} \
			DB_BACKENDS=${DB_BACKENDS:Q}
MAKE_FLAGS+=		BUILD_DIRS=${PKG_BUILD_DIRS:Q} DB_BACKENDS=${DB_BACKENDS:Q}

PLIST_VARS+=			shlibs

USE_PKGSRC_GCC_RUNTIME?=		no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=				yes
CONFIGURE_ARGS+=			ENABLE_SHARED=yes
BUILDLINK_DEPMETHOD.xmlada=		full
BUILDLINK_DEPMETHOD.gprlib=		full
BUILDLINK_DEPMETHOD.gnatcoll-core=	full
.else
CONFIGURE_ARGS+=			ENABLE_SHARED=no
.endif

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/\.relocatable\/|\.static-pic\/|lib\/.*\.so.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"
.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.include "../../devel/ada-libgpr-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-core-25/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
