# $NetBSD: Makefile,v 1.33 2010/05/21 09:52:59 adam Exp $

DISTNAME=	libsigc++-2.2.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsigc++/2.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bsieker@freenet.de
HOMEPAGE=	http://libsigc.sourceforge.net/
COMMENT=	Type-safe callback system for C++ programs

LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gm4 gmake perl:build
GNU_CONFIGURE=		yes

CONFLICTS+=		libsigc++2-[0-9]*

# supported according to the file README
GCC_REQD+=		3.2
# use something that can extract long filenames in GNU format on NetBSD 1.6.x
EXTRACT_USING=		bsdtar

PKGCONFIG_OVERRIDE=	sigc++.pc.in

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threads
.endif

.include "../../mk/bsd.pkg.mk"
