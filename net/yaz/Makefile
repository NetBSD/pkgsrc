# $NetBSD: Makefile,v 1.7 2004/10/03 00:18:02 tv Exp $
#

DISTNAME=	yaz-2.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://indexdata.dk/yaz
COMMENT=	C/C++ toolkit for the development of Z39.50v3/SRW clients and servers

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

PTHREAD_OPTS+=	native optional

.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
PLIST_SUBST+=	YAZTHREAD="@comment "
.else
PLIST_SUBST+=	YAZTHREAD=""
.endif

.include "../../mk/bsd.pkg.mk"
