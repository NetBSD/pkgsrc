# $NetBSD: Makefile,v 1.1 2013/04/12 12:32:39 rodent Exp $
#

DISTNAME=	aspell6-sr-0.02
PKGNAME=	${DISTNAME:S/6-/-/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/sr/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://srpski.org/aspell/
COMMENT=	Serbian language support for aspell
LICENSE=	gnu-lgpl-v2.1

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
