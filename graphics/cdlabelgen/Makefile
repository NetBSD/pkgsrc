# $NetBSD: Makefile,v 1.11 2003/07/21 16:51:38 martti Exp $

DISTNAME=	cdlabelgen-2.5.0
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

.include "../../mk/bsd.pkg.mk"
