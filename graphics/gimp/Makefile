# $NetBSD: Makefile,v 1.83 2003/05/02 11:55:17 wiz Exp $

DISTNAME=		gimp-1.2.3
PKGREVISION=	3
CATEGORIES=		graphics
DISTFILES=		# nothing

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.gimp.org/
COMMENT=		Image manipulation program similar to Photoshop[tm]

NO_BUILD=	yes

DEPENDS+=	gimp-base>=1.2.3nb1:../../graphics/gimp-base
DEPENDS+=	gimp-data>=1.2:../../graphics/gimp-data
DEPENDS+=	gimp-print>=4.2.0:../../print/gimp-print
DEPENDS+=	gimp-print-escputil>=4.2.0:../../print/gimp-print-escputil

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
