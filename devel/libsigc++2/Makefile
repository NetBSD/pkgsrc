# $NetBSD: Makefile,v 1.14 2005/12/23 19:27:50 heinz Exp $

DISTNAME=	libsigc++-2.0.16
PKGNAME=	libsigc++2-2.0.16
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsigc++/2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bsieker@freenet.de
HOMEPAGE=	http://libsigc.sourceforge.net/
COMMENT=	Type-safe callback system for C++ programs

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gm4 gmake
GNU_CONFIGURE=		yes

# supported according to the file README
GCC_REQD+=		3.2
# use something that can extract long filenames in GNU format on NetBSD 1.6.x
EXTRACT_USING=		nbpax

PKGCONFIG_OVERRIDE=	sigc++-2.0.pc.in

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threads
.endif

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/sigc++-2.0/sigc++/adaptors/lambda/macros
	${INSTALL_DATA_DIR} ${PREFIX}/include/sigc++-2.0/sigc++/adaptors/macros
	${INSTALL_DATA_DIR} ${PREFIX}/include/sigc++-2.0/sigc++/functors/macros
	${INSTALL_DATA_DIR} ${PREFIX}/include/sigc++-2.0/sigc++/macros

.include "../../mk/bsd.pkg.mk"
