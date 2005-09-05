# $NetBSD: Makefile,v 1.25 2005/09/05 15:56:53 wiz Exp $

DISTNAME=	pcre-6.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/programming/pcre/	\
		ftp://pcre.sourceforge.net/pub/pcre/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.pcre.org/
COMMENT=	Perl Compatible Regular Expressions library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

PKG_CONFIG_OVERRIDE=	libpcre.pc.in

TEST_TARGET=		test

# Avoid an ICE in gcc2 on sparc64
# use CONFIGURE_ARGS instead of the usual CONFIGURE_ENV as the latter just
# won't work with -this- configure
CONFIGURE_ARGS+=	F77=${FALSE}

.include "../../mk/bsd.pkg.mk"
