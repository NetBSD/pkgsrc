# $NetBSD: Makefile,v 1.87 2003/07/17 21:40:52 grant Exp $
#

DISTNAME=	gimp-1.2.5
CATEGORIES=	graphics
DISTFILES=	# nothing

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.gimp.org/
COMMENT=	GNU Image Manipulation Program

NO_BUILD=	YES

DEPENDS+=	gimp-base>=1.2.5:../../graphics/gimp-base
DEPENDS+=	gimp-data>=1.2:../../graphics/gimp-data
DEPENDS+=	gimp-print>=4.2.0:../../print/gimp-print
DEPENDS+=	gimp-print-escputil>=4.2.0:../../print/gimp-print-escputil

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
