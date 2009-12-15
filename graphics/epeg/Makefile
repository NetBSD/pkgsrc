# $NetBSD: Makefile,v 1.6 2009/12/15 21:48:00 joerg Exp $
#

DISTNAME=		epeg-0.9.0
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		Peter.Bex@student.kun.nl
HOMEPAGE=		http://www.enlightenment.org/Libraries/Epeg/
COMMENT=		Fast JPEG scaling library for thumbnail generation

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
