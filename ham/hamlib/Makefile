# $NetBSD: Makefile,v 1.11 2004/11/23 11:21:07 wulf Exp $
#

DISTNAME=	hamlib-1.2.3
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hamlib/}
#EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://hamlib.sourceforge.net/
COMMENT=	API for digital communications equipment

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
NO_EXPORT_CPP=	yes

CONFIGURE_ARGS+=--without-tcl-binding \
		--without-perl-binding

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/hamlib

.include "../../mk/bsd.pkg.mk"
