# $NetBSD: Makefile,v 1.3 2003/07/24 06:40:54 jmc Exp $
#

DISTNAME=	hamlib-1.1.4
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hamlib/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://hamlib.sourceforge/net/
COMMENT=	API for digital communications equipment

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=${WRKSRC}/libtool

CONFIGURE_ENV+=	CPP="${CPP}"

.include "../../mk/bsd.pkg.mk"
