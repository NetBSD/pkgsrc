# $NetBSD: Makefile,v 1.16 2004/04/24 23:43:27 grant Exp $

DISTNAME=	cdlabelgen-2.7.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.aczone.com/pub/tools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.aczone.com/tools/cdinsert/
COMMENT=	Generate frontcards and traycards for CDs

USE_PERL5=	run
NO_BUILDLINK=	yes
USE_LANGUAGES=	# empty

MAKE_ENV+=	SED="${SED}"
MAKE_ENV+=	MV="${MV}"

post-extract:
	cd ${WRKSRC} && ${CHMOD} go+r *

.include "../../mk/bsd.pkg.mk"
