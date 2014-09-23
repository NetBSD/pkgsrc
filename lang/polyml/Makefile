# $NetBSD: Makefile,v 1.12 2014/09/23 15:13:23 asau Exp $

DISTNAME=	polyml.5.5.2
PKGNAME=	polyml-5.5.2
PKGREVISION=	1
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

.include "options.mk"

.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
