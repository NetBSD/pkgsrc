# $NetBSD: Makefile,v 1.8 2022/07/25 19:22:23 wiz Exp $

DISTNAME=	libsigc++-1.2.7
PKGNAME=	libsigc++1-1.2.7
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsigc++/1.2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libsigcplusplus/libsigcplusplus
COMMENT=	Type-safe callback system for C++ programs

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gm4 gmake
USE_LANGUAGES=		c c++03

CONFLICTS+=		libsigc++-1.*

PKGCONFIG_OVERRIDE=	sigc++-1.2.pc.in

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threads
.endif

.include "../../mk/bsd.pkg.mk"
