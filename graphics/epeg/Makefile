# $NetBSD: Makefile,v 1.8 2010/12/23 11:44:36 dsainty Exp $
#

DISTNAME=		epeg-0.9.0
PKGREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		Peter.Bex@student.kun.nl
HOMEPAGE=		http://www.enlightenment.org/Libraries/Epeg/
COMMENT=		Fast JPEG scaling library for thumbnail generation

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
