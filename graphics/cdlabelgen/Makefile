# $NetBSD: Makefile,v 1.12 2003/08/03 20:44:28 jdolecek Exp $

DISTNAME=	cdlabelgen-2.6.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.aczone.com/pub/tools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.aczone.com/tools/cdinsert/
COMMENT=	Generate frontcards and traycards for CDs

USE_PERL5=	run
USE_BUILDLINK2=	yes

MAKE_ENV+=	SED="${SED}"
MAKE_ENV+=	MV="${MV}"

post-extract:
	cd ${WRKSRC} && chmod go+r *

.include "../../mk/bsd.pkg.mk"
