# $NetBSD: Makefile,v 1.8 2004/11/16 21:39:32 shannonjr Exp $
#

DISTNAME=		librfuncs-1.0.6
CATEGORIES=		devel
MASTER_SITES=		http://www.johnrshannon.com/NetBSD/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.johnrshannon.com/NetBSD/
COMMENT=		Provides missing POSIX *_r functions

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

TEST_TARGET=		check

.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threads
.else
CONFIGURE_ARGS+=	--enable-threads
.endif

.include "../../mk/bsd.pkg.mk"
