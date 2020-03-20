# $NetBSD: Makefile,v 1.59 2020/03/20 11:57:27 nia Exp $

DISTNAME=	libsigc++-2.10.2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsigc++/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libsigc.sourceforge.net/
COMMENT=	Type-safe callback system for C++ programs (v2)
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		gm4 gmake perl:build
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	sigc++.pc.in

CONFLICTS+=		libsigc++2-[0-9]*
GCC_REQD+=		4.8

# use something that can extract long filenames in GNU format on NetBSD 1.6.x
EXTRACT_USING=		bsdtar

TEST_TARGET=		check

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threads
.endif

BUILDLINK_API_DEPENDS.mm-common+=	mm-common>=0.9.10
.include "../../devel/mm-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
