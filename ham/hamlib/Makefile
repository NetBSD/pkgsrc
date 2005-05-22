# $NetBSD: Makefile,v 1.15 2005/05/22 20:08:08 jlam Exp $
#

DISTNAME=	hamlib-1.2.4
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hamlib/}
#EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://hamlib.sourceforge.net/
COMMENT=	API for digital communications equipment

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=--without-tcl-binding \
		--without-perl-binding \
		--without-python-binding

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/hamlib

.include "../../mk/bsd.pkg.mk"
