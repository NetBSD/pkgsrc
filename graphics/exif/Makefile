# $NetBSD: Makefile,v 1.2 2003/10/14 12:31:18 salo Exp $
#

DISTNAME=	exif-0.6
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libexif/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://libexif.sourceforge.net/
COMMENT=	Grab Exif information from digital camera images

DEPENDS+=	popt>=1.7:../../devel/popt

HAS_CONFIGURE=	YES
USE_BUILDLINK2=	YES

CONFIGURE_ARGS+=	--with-popt-prefix=${PREFIX}	\
			--prefix=${PREFIX}

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../graphics/libexif/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
