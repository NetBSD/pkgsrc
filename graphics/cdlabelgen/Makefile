# $NetBSD: Makefile,v 1.18 2005/07/16 01:19:10 jlam Exp $

DISTNAME=	cdlabelgen-2.7.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.aczone.com/pub/tools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.aczone.com/tools/cdinsert/
COMMENT=	Generate frontcards and traycards for CDs

USE_TOOLS+=	perl:run
USE_LANGUAGES=	# empty

MAKE_ENV+=	SED="${SED}"
MAKE_ENV+=	MV="${MV}"

post-extract:
	cd ${WRKSRC} && ${CHMOD} go+r *

.include "../../mk/bsd.pkg.mk"
