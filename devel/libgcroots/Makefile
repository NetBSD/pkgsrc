# $NetBSD: Makefile,v 1.2 2009/11/22 10:53:09 obache Exp $
#

DISTNAME=	libgcroots-0.2.2
CATEGORIES=	devel
MASTER_SITES=	http://sigscheme.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/sigscheme/wiki/libgcroots
COMMENT=	Garbage collector supporting library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	gcroots.pc.in

# This directory is used for c++ interface, but not build by default.
post-install:
	rmdir ${DESTDIR}${PREFIX}/include/libgcroots

.include "../../mk/bsd.pkg.mk"
