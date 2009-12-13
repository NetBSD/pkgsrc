# $NetBSD: Makefile,v 1.2 2009/12/13 23:26:25 asau Exp $

DISTNAME=	polyml.5.3
PKGNAME=	polyml-5.3
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

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
