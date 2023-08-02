# $NetBSD: Makefile,v 1.24 2023/08/02 19:21:54 nia Exp $
#

DISTNAME=	gambit-${GAMBC_DIST_VERSION:S,.,_,}
PKGNAME=	gambc-${GAMBC_VERSION}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://gambitscheme.org/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gambitscheme.org/
COMMENT=	GambitC Scheme System
LICENSE=	apache-2.0 AND gnu-lgpl-v2.1

# bin/scheme-r5rs
CONFLICTS+=	scheme48>=1.2

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--enable-single-host
CONFIGURE_ARGS+=	--enable-cplusplus
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--disable-absolute-shared-libs # DESTDIR bug?
CONFIGURE_ARGS+=	--enable-default-runtime-options=f8,-8,t8
CONFIGURE_ARGS+=	--enable-compiler-name=gsc-gambit
CONFIGURE_ARGS+=	--enable-interpreter-name=gsi-gambit
CONFIGURE_ARGS+=	--enable-gcc-opts

INFO_FILES=		yes
MAKE_FILE=		makefile

BUILD_TARGET+=		bootstrap
TEST_TARGET=		check

WRKSRC=			${WRKDIR}/gambit-${PKGVERSION_NOREV}

# Fails with C++14 default language
FORCE_CXX_STD=		c++03

CHECK_PORTABILITY_SKIP=		prebuilt/*/*
DLOPEN_REQUIRE_PTHREADS=	no

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
SUBST_FILES.build=	makefile.in */makefile.in */*/makefile.in
SUBST_MESSAGE.build=	Preparing build-time and installation configuration.
SUBST_SED.build=	-e 's|v${GAMBC_DIST_VERSION}||'
SUBST_SED.build+=	-e 's|@target_vendor@|The NetBSD Foundation, Inc.|g'
SUBST_STAGE.build=	pre-configure
SUBST_VARS.build+=	PACKAGE_SUBDIR PACKAGE_VERSION PACKAGE_STRING

SUBST_CLASSES+=		flags
SUBST_FILES.flags=	makefile.in gsc/makefile.in gsi/makefile.in lib/makefile.in
SUBST_MESSAGE.flags=	putting flags first
SUBST_SED.flags=	-e 's|^\(FLAGS_OBJ = \).*|\1 ${CFLAGS}|'
SUBST_SED.flags+=	-e 's|^\(FLAGS_DYN = \).*|\1 ${CFLAGS}|'
SUBST_STAGE.flags=	pre-configure

PACKAGE_SUBDIR=		# empty
PACKAGE_VERSION=	${PKGVERSION_NOREV}
PACKAGE_STRING=		${${PKGBASE} ${PKGVERSION_NOREV}:L}

.include "version.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
