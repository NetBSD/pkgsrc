# $NetBSD: Makefile,v 1.14 2014/09/29 00:55:00 asau Exp $

DISTNAME=	polyml.5.5.2
PKGNAME=	polyml-5.5.2
PKGREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=polyml/}

MAINTAINER=	asau@NetBSD.org
HOMEPAGE=	http://polyml.org/
COMMENT=	Poly/ML is an implementation of Standard ML

# ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64 *-*-sparc *-*-powerpc

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-libffi
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
TEST_TARGET=	tests

PKGCONFIG_OVERRIDE=	libpolyml/polyml.pc.in

SUBST_CLASSES+=		rpath
SUBST_SED.rpath=	-e s';-L@libdir@;-L@libdir@ ${COMPILER_RPATH_FLAG}@libdir@;g'
SUBST_FILES.rpath=	libpolyml/polyml.pc.in
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Adding RPATH flag to pkg-config file.

SUBST_CLASSES+=		compiler-rpath
SUBST_SED.compiler-rpath=	-e s';@COMPILER_RPATH_FLAG@;${COMPILER_RPATH_FLAG};g'
SUBST_FILES.compiler-rpath=	polyc.in
SUBST_STAGE.compiler-rpath=	pre-configure
SUBST_MESSAGE.compiler-rpath=	Adding RPATH flag to compiler wrapper.

.include "options.mk"

.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
