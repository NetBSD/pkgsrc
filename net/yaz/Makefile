# $NetBSD: Makefile,v 1.1.1.1 2003/05/16 12:17:25 dmcmahill Exp $
#

DISTNAME=	yaz-2.0
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://indexdata.dk/yaz
COMMENT=	C/C++ toolkit for the development of Z39.50v3/SRW clients and servers

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
