# $NetBSD: Makefile,v 1.5 2004/02/14 17:21:43 jlam Exp $
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

CONFIGURE_ENV+=	CPP="${CPP}"

.include "../../mk/bsd.pkg.mk"
