# $NetBSD: Makefile,v 1.4 2004/01/24 13:40:43 grant Exp $
#

DISTNAME=	hamlib-1.1.4
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hamlib/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://hamlib.sourceforge/net/
COMMENT=	API for digital communications equipment

USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=${WRKSRC}/libtool

CONFIGURE_ENV+=	CPP="${CPP}"

.include "../../mk/bsd.pkg.mk"
