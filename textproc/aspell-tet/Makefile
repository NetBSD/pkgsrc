# $NetBSD: Makefile,v 1.1 2013/04/13 11:54:12 rodent Exp $
#

DISTNAME=	aspell5-tet-0.1.1
PKGNAME=	${DISTNAME:S/5-/-/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/tet/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/tetum/dictionaries/spellcheckers.html
COMMENT=	Tetum language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
