# $NetBSD: Makefile,v 1.10 2004/11/03 17:10:05 minskim Exp $
#

DISTNAME=	exif-0.6.9
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libexif/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://libexif.sourceforge.net/
COMMENT=	Grab Exif information from digital camera images

HAS_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES

CONFIGURE_ARGS+=	--with-popt-prefix=${PREFIX}	\
			--prefix=${PREFIX}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
