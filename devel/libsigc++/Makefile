# $NetBSD: Makefile,v 1.22 2005/05/13 16:54:12 jlam Exp $

DISTNAME=	libsigc++-1.2.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsigc++/1.2/}

MAINTAINER=	bsieker@freenet.de
HOMEPAGE=	http://libsigc.sourceforge.net/
COMMENT=	Type-safe callback system for C++ programs

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		m4 make
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE=	sigc++-1.2.pc.in

CONFIGURE_ENV+=		ac_cv_prog_M4=${TOOLS_M4:Q}

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threads
.endif

.include "../../mk/bsd.pkg.mk"
