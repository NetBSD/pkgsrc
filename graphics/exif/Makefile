# $NetBSD: Makefile,v 1.6 2004/04/23 23:58:25 wiz Exp $
#

DISTNAME=	exif-0.6
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libexif/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://libexif.sourceforge.net/
COMMENT=	Grab Exif information from digital camera images

HAS_CONFIGURE=	YES
USE_BUILDLINK3=	YES

CONFIGURE_ARGS+=	--with-popt-prefix=${PREFIX}	\
			--prefix=${PREFIX}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
