# $NetBSD: Makefile,v 1.1.1.1 2009/12/21 19:18:25 reed Exp $
#

DISTNAME=	gtest-1.4.0
PKGNAME=	${DISTNAME:S/gtest/googletest/}
CATEGORIES=	devel
MASTER_SITES=	http://googletest.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://code.google.com/p/googletest/
COMMENT=	Google's C++ testing framework

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++ c
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
