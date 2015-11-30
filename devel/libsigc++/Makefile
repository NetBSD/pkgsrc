# $NetBSD: Makefile,v 1.48 2015/11/30 14:27:44 adam Exp $

DISTNAME=	libsigc++-2.6.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsigc++/2.6/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libsigc.sourceforge.net/
COMMENT=	Type-safe callback system for C++ programs
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gm4 gmake perl:build
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	sigc++.pc.in

CONFLICTS+=		libsigc++2-[0-9]*
GCC_REQD+=		4.7

# use something that can extract long filenames in GNU format on NetBSD 1.6.x
EXTRACT_USING=		bsdtar

TEST_TARGET=		check

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threads
.endif

.include "../../mk/bsd.pkg.mk"
