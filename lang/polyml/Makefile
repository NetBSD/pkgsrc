# $NetBSD: Makefile,v 1.7 2012/10/08 14:26:03 asau Exp $

DISTNAME=	polyml.5.5
PKGNAME=	polyml-5.5
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=polyml/}

MAINTAINER=	asau@NetBSD.org
HOMEPAGE=	http://polyml.org/
COMMENT=	Poly/ML is an implementation of Standard ML

# ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64 *-*-sparc *-*-powerpc
# Dumps core on NetBSD/amd64

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
TEST_TARGET=	tests

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
