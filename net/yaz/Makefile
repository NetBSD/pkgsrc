# $NetBSD: Makefile,v 1.3 2003/07/17 22:52:06 grant Exp $
#

DISTNAME=	yaz-2.0
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://indexdata.dk/yaz
COMMENT=	C/C++ toolkit for the development of Z39.50v3/SRW clients and servers

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
