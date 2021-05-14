# $NetBSD: Makefile,v 1.13 2021/05/14 14:13:22 nia Exp $
#

DISTNAME=		epeg-0.9.0
PKGREVISION=		4
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		Peter.Bex@student.kun.nl
#HOMEPAGE=		https://www.enlightenment.org/Libraries/Epeg/
COMMENT=		Fast JPEG scaling library for thumbnail generation
LICENSE=		original-bsd # ish

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
