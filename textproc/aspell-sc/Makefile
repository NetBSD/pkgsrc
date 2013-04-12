# $NetBSD: Makefile,v 1.1 2013/04/12 12:19:29 rodent Exp $
#

DISTNAME=	aspell5-sc-1.0
PKGNAME=	${DISTNAME:S/5-/-/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/sc/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.ditzionariu.org/
COMMENT=	Sardinian language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
