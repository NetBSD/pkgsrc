# $NetBSD: Makefile,v 1.9 2003/06/02 01:19:31 jschauma Exp $

DISTNAME=	cdlabelgen-2.5.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.aczone.com/pub/tools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.aczone.com/tools/cdinsert/
COMMENT=	generate frontcards and traycards for CDs

USE_PERL5=	run
USE_BUILDLINK2=	yes

MAKE_ENV+=	SED="${SED}"
MAKE_ENV+=	MV="${MV}"

.include "../../mk/bsd.pkg.mk"
