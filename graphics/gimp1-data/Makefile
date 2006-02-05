# $NetBSD: Makefile,v 1.9 2006/02/05 23:09:31 joerg Exp $
#

DISTNAME=	gimp-data-extras-1.2.0
PKGNAME=	gimp-data-1.2
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/v1.2/v1.2.5/ \
		ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/v1.2/v1.2.5/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gimp/v1.2/v1.2.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gimp.org/
COMMENT=	GNU Image Manipulation Program (extra brushes and patterns)

CONFLICTS+=	gimp<=1.2.3 gimp>=2.0.0

GNU_CONFIGURE=	YES

.include "../../graphics/gimp1-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
