# $NetBSD: Makefile,v 1.3 2020/01/18 23:35:24 rillig Exp $
#

DISTNAME=	aspell5-tet-0.1.1
PKGNAME=	${DISTNAME:S/5-/-/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/tet/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/tetum/dictionaries/spellcheckers.html
COMMENT=	Tetum language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
