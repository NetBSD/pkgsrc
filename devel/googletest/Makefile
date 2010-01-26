# $NetBSD: Makefile,v 1.3 2010/01/26 01:20:57 reed Exp $
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

SUBST_CLASSES+=		rpathfix
SUBST_FILES.rpathfix=	scripts/gtest-config.in
SUBST_MESSAGE.rpathfix=	Adding rpath to gtest-config
SUBST_SED.rpathfix=	-e 's/-L$${libdir}/${COMPILER_RPATH_FLAG}$${libdir} -L$${libdir}/g'
SUBST_STAGE.rpathfix=	pre-configure

.include "../../mk/bsd.pkg.mk"
