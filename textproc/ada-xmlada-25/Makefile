# $NetBSD: Makefile,v 1.3 2025/09/22 09:52:12 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-${GNAT_NAME}-25.0.0
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	xmlada
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/xmlada
COMMENT=	XML/Ada: An XML parser for Ada95, release 25
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

USE_LANGUAGES=	ada

GNU_CONFIGURE=		yes

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

SUBST_CLASSES+=		fixver
SUBST_STAGE.fixver=	post-extract
SUBST_FILES.fixver=	configure
SUBST_MESSAGE.fixver=	Fix version in ${SUBST_FILES.fixver}
SUBST_SED.fixver=	-e 's,18.0w,25.0w,g'

GNU_CONFIGURE_PREFIX=	${GNAT_PREFIX}

PLIST_VARS+=			shlibs

USE_PKGSRC_GCC_RUNTIME?=	no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=			yes
CONFIGURE_ARGS+=		--enable-shared
.else
CONFIGURE_ARGS+=		--disable-shared
.endif

TEST_TARGET=		test run_test

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/\.relocatable\/|\.static-pic\/|lib\/.*\.so.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
