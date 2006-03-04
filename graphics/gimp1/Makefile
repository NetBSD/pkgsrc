# $NetBSD: Makefile,v 1.5 2006/03/04 21:29:48 jlam Exp $
#

DISTNAME=	gimp-1.2.5
PKGREVISION=	1
CATEGORIES=	graphics
DISTFILES=	# nothing

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gimp.org/
COMMENT=	GNU Image Manipulation Program

NO_BUILD=	YES

DEPENDS+=	gimp-base>=1.2.5:../../graphics/gimp1-base
DEPENDS+=	gimp-data>=1.2:../../graphics/gimp1-data
DEPENDS+=	gimp-print>=4.2.0:../../print/gimp-print
DEPENDS+=	gimp-print-escputil>=4.2.0:../../print/gimp-print-escputil

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
