# $NetBSD: Makefile,v 1.8 2005/05/13 16:54:13 jlam Exp $

DISTNAME=	libsigc++-2.0.11
PKGNAME=	libsigc++2-2.0.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsigc++/2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bsieker@freenet.de
HOMEPAGE=	http://libsigc.sourceforge.net/
COMMENT=	Type-safe callback system for C++ programs

USE_GNU_TOOLS+=		m4 make
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	sigc++-2.0.pc.in

CONFIGURE_ENV+=		ac_cv_prog_M4=${TOOLS_M4:Q}

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
