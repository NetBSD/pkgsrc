# $NetBSD: Makefile,v 1.16 2006/02/05 23:09:42 joerg Exp $
#

DISTNAME=	hamlib-1.2.4
PKGREVISION=	1
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
