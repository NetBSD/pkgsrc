# $NetBSD: Makefile,v 1.1 2013/04/27 10:43:32 rodent Exp $
#

DISTNAME=	br.ispell-2.4
PKGNAME=	ispell-br-2.4
CATEGORIES=	textproc
MASTER_SITES=	http://www.ime.usp.br/~ueda/br.ispell/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.ime.usp.br/~ueda/br.ispell/summary.html
COMMENT=	Brazilian Portuguese dictionary for interactive spelling checker
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	Makefile
SUBST_MESSAGE.paths=	Fixing paths.
SUBST_SED.paths=	-e "s|prefix=/usr/local|prefix=${PREFIX}|1"
SUBST_SED.paths+=	-e "s|/usr/lib/ispell|${PREFIX}/lib|1"
SUBST_STAGE.paths=	post-patch

BUILD_MAKE_FLAGS+=	AWK=${AWK}

DEPENDS+=	ispell-[0-9]*:../../textproc/ispell
.include "../../mk/bsd.pkg.mk"
