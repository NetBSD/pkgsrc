# $NetBSD: Makefile,v 1.4 2020/01/18 23:35:27 rillig Exp $
#

DISTNAME=	ispell-ku-0.20
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=myspellkurdish/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://myspellkurdish.sourceforge.net/
COMMENT=	Kurdish dictionary for interactive spelling checker
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	lib

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	Makefile
SUBST_MESSAGE.paths=	Fixing paths.
SUBST_SED.paths=	-e "s|/usr/local|${PREFIX}|1"
SUBST_SED.paths+=	-e "s|/ispell||1"
SUBST_SED.paths+=	-e "s|/usr/bin/install|${INSTALL}|1"
SUBST_STAGE.paths=	pre-configure

DEPENDS+=	ispell-[0-9]*:../../textproc/ispell
.include "../../mk/bsd.pkg.mk"
