# $NetBSD: Makefile,v 1.20 2005/12/30 15:00:02 ben Exp $

DISTNAME=	cdlabelgen-3.6.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.aczoom.com/pub/tools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.aczoom.com/tools/cdinsert/
COMMENT=	Generate frontcards and traycards for CDs

USE_TOOLS+=	perl:run
USE_LANGUAGES=	# empty

MAKE_ENV+=	SED=${SED:Q}
MAKE_ENV+=	MV=${MV:Q}

post-extract:
	cd ${WRKSRC} && ${CHMOD} go+r *

.include "../../mk/bsd.pkg.mk"
