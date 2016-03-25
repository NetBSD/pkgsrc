# $NetBSD: Makefile,v 1.14 2016/03/25 21:11:47 joerg Exp $
#

DISTNAME=	gambc-${GAMBC_DIST_VERSION}
PKGNAME=	gambc-${GAMBC_VERSION}
CATEGORIES=	lang
MASTER_SITES=	http://www.iro.umontreal.ca/~gambit/download/gambit/v4.6/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.iro.umontreal.ca/~gambit/
COMMENT=	GambitC Scheme System

# bin/scheme-r5rs
CONFLICTS+=	scheme48>=1.2

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--enable-single-host
CONFIGURE_ARGS+=	--enable-cplusplus
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--disable-absolute-shared-libs # DESTDIR bug?
###
### XXX On NetBSD/amd64 4.99.61, gcc had a resident memory size of over 384MB
###	while building this and ultimately exhausted all 1GB of swap I had.
###	See the documentation for more information.  (This was due to using
###	-fmodulo-sched, gcc 4.1.3).
###
CONFIGURE_ARGS+=	--disable-gcc-opts

INFO_FILES=		yes
MAKE_FILE=		makefile

BUILD_TARGET+=		bootstrap
TEST_TARGET=		check

CHECK_PORTABILITY_SKIP=	prebuilt/*/*
DLOPEN_REQUIRE_PTHREADS=no

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

GAMBC_MAKE_FLAGS=	prefix=${PREFIX}
GAMBC_MAKE_FLAGS+=	includedir=${PREFIX}/include
GAMBC_MAKE_FLAGS+=	bindir=${PREFIX}/bin
GAMBC_MAKE_FLAGS+=	infodir=${PREFIX}/${PKGINFODIR}
GAMBC_MAKE_FLAGS+=	libdir=${PREFIX}/lib/
GAMBC_MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}
GAMBC_MAKE_FLAGS+=	docdir=${PREFIX}/share/doc/${PKGBASE}
GAMBC_MAKE_FLAGS+=	infodir=${PREFIX}/${PKGINFODIR}
GAMBC_MAKE_FLAGS+=	emacsdir=${PREFIX}/share/emacs/site-lisp

MAKE_FLAGS+=		${GAMBC_MAKE_FLAGS}

SUBST_CLASSES+=		build
SUBST_FILES.build=	configure
SUBST_FILES.build+=	makefile.in */makefile.in */*/makefile.in
SUBST_MESSAGE.build=	Preparing build-time and installation configuration.
SUBST_SED.build=	-e 's|v${GAMBC_DIST_VERSION}||'
SUBST_SED.build+=	-e 's|@target_vendor@|The NetBSD Foundation, Inc.|g'
SUBST_STAGE.build=	pre-configure
SUBST_VARS.build+=	PACKAGE_SUBDIR PACKAGE_VERSION
SUBST_VARS.build+=	PACKAGE_STRING

PACKAGE_SUBDIR=		# empty
PACKAGE_VERSION=	${PKGVERSION}
PACKAGE_STRING=		${${PKGBASE} ${PKGVERSION}:L}

.include "version.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
