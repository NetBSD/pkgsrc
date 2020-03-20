# $NetBSD: Makefile,v 1.3 2020/03/20 11:57:28 nia Exp $

DISTNAME=	libsigc++-3.0.0
PKGNAME=	${DISTNAME:S/-/3-/}
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsigc++/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libsigc.sourceforge.net/
COMMENT=	Type-safe callback system for C++ programs
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		gm4 gmake perl:build
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	sigc++.pc.in

GCC_REQD+=		4.8

TEST_TARGET=		check

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threads
.endif

BUILDLINK_API_DEPENDS.mm-common+=	mm-common>=0.9.10
.include "../../devel/mm-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
