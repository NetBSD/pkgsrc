# $NetBSD: Makefile,v 1.80 2002/02/15 20:55:58 drochner Exp $

DISTNAME=		gimp-1.2.3
PKGREVISION=		1
CATEGORIES=		graphics
DISTFILES=		# nothing

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.gimp.org/
COMMENT=		Image manipulation program similar to Photoshop[tm]

NO_BUILD=	yes

DEPENDS+=	gimp-base-1.2.3:../../graphics/gimp-base
DEPENDS+=	gimp-data>=1.2:../../graphics/gimp-data
DEPENDS+=	gimp-print>=4.2.0:../../print/gimp-print
DEPENDS+=	gimp-print-escputil>=4.2.0:../../print/gimp-print-escputil

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
