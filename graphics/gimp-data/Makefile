# $NetBSD: Makefile,v 1.5 2003/05/23 18:04:33 salo Exp $
#

DISTNAME=	gimp-data-extras-1.2.0
PKGNAME=	gimp-data-1.2
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/v1.2/v1.2.4/ \
		ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/v1.2/v1.2.4/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gimp/v1.2/v1.2.4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.gimp.org/
COMMENT=	GNU Image Manipulation Program (extra brushes and patterns)

CONFLICTS+=	gimp<=1.2.3

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

.include "../../graphics/gimp-base/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
