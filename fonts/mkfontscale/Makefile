# $NetBSD: Makefile,v 1.1.1.1 2002/05/20 12:30:29 wiz Exp $
#

DISTNAME=	mkfontscale-20020418
CATEGORIES=	fonts
MASTER_SITES=	http://www.pps.jussieu.fr/~jch/software/files/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://www.pps.jussieu.fr/~jch/software/files/
COMMENT=	create an index of scalable font files for X

USE_IMAKE=	yes

WRKSRC=		${WRKDIR}/mkfontscale

.include "../../graphics/freetype2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
