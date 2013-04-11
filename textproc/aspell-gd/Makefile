# $NetBSD: Makefile,v 1.1 2013/04/11 00:19:47 rodent Exp $
#

DISTNAME=	aspell5-gd-0.1.1-1
PKGNAME=	${DISTNAME:S/5-/-/1:S/-1/.1/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/gd/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://borel.slu.edu/crubadan/
COMMENT=	Scottish Gaelic language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
