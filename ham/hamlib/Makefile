# $NetBSD: Makefile,v 1.9 2004/09/22 22:33:13 wulf Exp $
#

DISTNAME=	hamlib-1.2.2
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hamlib/}
#EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://hamlib.sourceforge/net/
COMMENT=	API for digital communications equipment

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
NO_EXPORT_CPP=	yes

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/hamlib

.include "../../mk/bsd.pkg.mk"
