# $NetBSD: Makefile,v 1.37 2007/06/17 17:05:08 joerg Exp $

DISTNAME=	pcre-7.1
CATEGORIES=	devel
PKGREVISION=	1
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/programming/pcre/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.pcre.org/
COMMENT=	Perl Compatible Regular Expressions library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-utf8

SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Fixing rpath output in pcre-config
SUBST_FILES.rpath=	pcre-config.in
SUBST_VARS.rpath=	COMPILER_RPATH_FLAG

PKGCONFIG_OVERRIDE=	libpcre.pc.in libpcrecpp.pc.in

# needs a stacksize of 4mb, default is 2mb
TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
