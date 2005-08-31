# $NetBSD: Makefile,v 1.21.2.1 2005/08/31 08:48:45 snj Exp $

DISTNAME=	pcre-6.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/programming/pcre/	\
		ftp://pcre.sourceforge.net/pub/pcre/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	proff@NetBSD.org
HOMEPAGE=	http://www.pcre.org/
COMMENT=	Perl Compatible Regular Expressions library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_TARGET=		all libpcrecpp.la pcrecpp_unittest \
			pcre_scanner_unittest pcre_stringpiece_unittest
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

PKG_CONFIG_OVERRIDE=	libpcre.pc.in

TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
