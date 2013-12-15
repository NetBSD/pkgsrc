# $NetBSD: Makefile,v 1.9 2013/12/15 18:35:22 asau Exp $

DISTNAME=	polyml.5.5.1
PKGNAME=	polyml-5.5.1
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

SUBST_CLASSES+=			fix-rpath-flag
SUBST_STAGE.fix-rpath-flag=	pre-configure
SUBST_MESSAGE.fix-rpath-flag=	Fixing RPATH flag.
SUBST_FILES.fix-rpath-flag=	buildpolyc
SUBST_SED.fix-rpath-flag=	-e 's:@COMPILER_RPATH_FLAG@:${COMPILER_RPATH_FLAG}:g'

.include "options.mk"

.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
