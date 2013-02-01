# $NetBSD: Makefile,v 1.16 2013/02/01 22:21:05 wiz Exp $
#

DISTNAME=		librfuncs-1.0.7
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.johnrshannon.com/NetBSD/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.johnrshannon.com/NetBSD/
COMMENT=		Provides missing POSIX *_r functions

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

TEST_TARGET=		check
PTHREAD_AUTO_VARS=	no

.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threads
.else
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--with-thread-cflags=${PTHREAD_CFLAGS:M*:Q}
CONFIGURE_ARGS+=	--with-thread-ldflags=${PTHREAD_LDFLAGS:M*:Q}
.endif

.include "../../mk/bsd.pkg.mk"
