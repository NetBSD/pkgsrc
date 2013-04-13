# $NetBSD: Makefile,v 1.1 2013/04/13 12:07:33 rodent Exp $
#

DISTNAME=	aspell5-tn-1.0.1-0
PKGNAME=	${DISTNAME:S/5-/-/1:S/-0/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/tn/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://borel.slu.edu/crubadan/index.html
COMMENT=	Setswana language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
