# $NetBSD: Makefile,v 1.10 2013/01/26 21:36:26 adam Exp $
#

DISTNAME=		epeg-0.9.0
PKGREVISION=		4
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		Peter.Bex@student.kun.nl
HOMEPAGE=		http://www.enlightenment.org/Libraries/Epeg/
COMMENT=		Fast JPEG scaling library for thumbnail generation

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
