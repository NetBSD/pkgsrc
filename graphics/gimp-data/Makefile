# $NetBSD: Makefile,v 1.9 2004/01/03 18:49:42 reed Exp $
#

DISTNAME=	gimp-data-extras-1.2.0
PKGNAME=	gimp-data-1.2
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/v1.2/v1.2.5/ \
		ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/v1.2/v1.2.5/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gimp/v1.2/v1.2.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.gimp.org/
COMMENT=	GNU Image Manipulation Program (extra brushes and patterns)

CONFLICTS+=	gimp<=1.2.3

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

.include "../../graphics/gimp-base/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
