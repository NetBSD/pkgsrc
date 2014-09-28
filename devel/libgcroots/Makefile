# $NetBSD: Makefile,v 1.6 2014/09/28 03:16:17 obache Exp $
#

DISTNAME=	libgcroots-0.2.3
CATEGORIES=	devel
MASTER_SITES=	http://sigscheme.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/sigscheme/wiki/libgcroots
COMMENT=	Garbage collector supporting library
#LICENSE=	# See ${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	gcroots.pc.in

# This directory is used for c++ interface, but not build by default.
post-install:
	rmdir ${DESTDIR}${PREFIX}/include/libgcroots

.include "../../mk/bsd.pkg.mk"
