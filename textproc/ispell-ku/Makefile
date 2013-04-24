# $NetBSD: Makefile,v 1.1 2013/04/24 03:32:37 rodent Exp $
#

DISTNAME=	ispell-ku-0.20
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=myspellkurdish/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://myspellkurdish.sourceforge.net/
COMMENT=	Kurdish dictionary for interactive spelling checker
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	lib

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	Makefile
SUBST_MESSAGE.paths=	Fixing paths.
SUBST_SED.paths=	-e "s|/usr/local|${PREFIX}|1"
SUBST_SED.paths+=	-e "s|/ispell||1"
SUBST_STAGE.paths=	pre-configure

DEPENDS+=	ispell-[0-9]*:../../textproc/ispell
.include "../../mk/bsd.pkg.mk"
