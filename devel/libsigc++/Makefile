# $NetBSD: Makefile,v 1.50 2016/07/09 06:38:09 wiz Exp $

DISTNAME=	libsigc++-2.8.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsigc++/${PKGVERSION_NOREV:R}/}
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
