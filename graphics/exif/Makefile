# $NetBSD: Makefile,v 1.1.1.1 2003/10/01 05:57:05 itojun Exp $
#

DISTNAME=	exif-0.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libexif/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://libexif.sourceforge.net/
COMMENT=	Grab Exif information from digital camera images

DEPENDS+=	popt>=1.7:../../devel/popt

HAS_CONFIGURE=	YES

CONFIGURE_ARGS+=--with-popt-prefix=${PREFIX} --prefix=${PREFIX}

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../graphics/libexif/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
