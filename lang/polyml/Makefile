# $NetBSD: Makefile,v 1.4 2012/06/14 22:23:36 sbd Exp $

DISTNAME=	polyml.5.4.1
PKGNAME=	polyml-5.4.1
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=polyml/}

MAINTAINER=	asau@NetBSD.org
HOMEPAGE=	http://polyml.org/
COMMENT=	Poly/ML is an implementation of Standard ML

# ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64 *-*-sparc *-*-powerpc
# Dumps core on NetBSD/amd64

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
TEST_TARGET=	tests

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
