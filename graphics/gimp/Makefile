# $NetBSD: Makefile,v 1.85 2003/05/23 18:04:31 salo Exp $
#

DISTNAME=	gimp-1.2.4
CATEGORIES=	graphics
DISTFILES=	# nothing

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.gimp.org/
COMMENT=	GNU Image Manipulation Program

NO_BUILD=	YES

DEPENDS+=	gimp-base>=1.2.4:../../graphics/gimp-base
DEPENDS+=	gimp-data>=1.2:../../graphics/gimp-data
DEPENDS+=	gimp-print>=4.2.0:../../print/gimp-print
DEPENDS+=	gimp-print-escputil>=4.2.0:../../print/gimp-print-escputil

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
