# $NetBSD: Makefile,v 1.1.1.1 2003/06/26 22:42:23 wulf Exp $
#

DISTNAME=	hamlib-1.1.4
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hamlib/}

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://hamlib.sourceforge/net/
COMMENT=	API for digital communications equipment

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
