# $NetBSD: Makefile,v 1.4 2003/05/02 11:55:18 wiz Exp $

DISTNAME=	gimp-data-extras-1.2.0
PKGNAME=	gimp-data-1.2
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/v1.2/v1.2.3/ \
		ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/v1.2/v1.2.3/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gimp/v1.2/v1.2.3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.gimp.org/
COMMENT=	extra brushes and patterns for the GIMP

CONFLICTS+=		gimp<=1.2.3

USE_BUILDLINK2=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../graphics/gimp-base/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
