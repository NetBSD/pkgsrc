# $NetBSD: Makefile,v 1.35 2007/05/03 12:27:54 wiz Exp $

DISTNAME=	pcre-7.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/programming/pcre/	\
		ftp://pcre.sourceforge.net/pub/pcre/
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

PKGCONFIG_OVERRIDE=	libpcre.pc.in libpcrecpp.pc.in

# needs a stacksize of 4mb, default is 2mb
TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
