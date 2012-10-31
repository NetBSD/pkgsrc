# $NetBSD: Makefile,v 1.3 2012/10/31 11:17:21 asau Exp $

DISTNAME=	libsigc++-1.2.7
PKGNAME=	libsigc++1-1.2.7
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsigc++/1.2/}

MAINTAINER=	bsieker@freenet.de
HOMEPAGE=	http://libsigc.sourceforge.net/
COMMENT=	Type-safe callback system for C++ programs

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gm4 gmake
USE_LANGUAGES=		c c++

CONFLICTS+=		libsigc++-1.*

PKGCONFIG_OVERRIDE=	sigc++-1.2.pc.in

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threads
.endif

.include "../../mk/bsd.pkg.mk"
