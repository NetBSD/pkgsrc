# $NetBSD: Makefile,v 1.2 2003/06/02 01:17:37 jschauma Exp $
#

DISTNAME=	yaz-2.0
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://indexdata.dk/yaz
COMMENT=	C/C++ toolkit for the development of Z39.50v3/SRW clients and servers

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
