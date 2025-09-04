# $NetBSD: Makefile,v 1.3 2025/09/04 07:53:28 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-${GNAT_NAME}-25.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gnatcoll-bindings
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gnatcoll-bindings
COMMENT=	The GNAT Components Collection (GNATcoll) - Bindings, release 25
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake grep

USE_LANGUAGES=	c c++ ada

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

.include "options.mk"

SUBST_CLASSES+=		fixver
SUBST_STAGE.fixver=	post-extract
SUBST_FILES.fixver=	version_information
SUBST_SED.fixver=	-e 's,0.0,25.0,g'
SUBST_MESSAGE.fixver=	Fix version information

MAKE_FLAGS+=	BINDINGS=${BINDINGS:Q}
MAKE_FLAGS+=	PYTHON=${PYTHONBIN:Q} prefix=${DESTDIR}${GNAT_PREFIX} BUILD=PROD

PLIST_VARS+=				shlibs

USE_PKGSRC_GCC_RUNTIME?=		no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=				yes
MAKE_FLAGS+=				ENABLE_SHARED=yes
BUILDLINK_DEPMETHOD.xmlada-25=		full
BUILDLINK_DEPMETHOD.libgpr-25=		full
BUILDLINK_DEPMETHOD.gnatcoll-core-25=	full
.else
MAKE_FLAGS+=				ENABLE_SHARED=no
.endif

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/\.relocatable\/|\.static-pic\/|lib\/.*\.so.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"
.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.include "../../devel/ada-libgpr-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-core-25/buildlink3.mk"

.include "../../lang/python/tool.mk"

.include "../../mk/bsd.pkg.mk"
