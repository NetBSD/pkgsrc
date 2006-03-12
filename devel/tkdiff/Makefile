# $NetBSD: Makefile,v 1.18 2006/03/12 07:39:36 minskim Exp $
#

DISTNAME=	tkdiff
PKGNAME=	${DISTNAME}-4.0.2
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tkdiff/}
EXTRACT_SUFX=	.zip

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/tkdiff/
COMMENT=	Graphical 2-way diff/merge tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DIST_SUBDIR=	${PKGNAME_NOREV}
NO_BUILD=	yes
NO_CONFIGURE=	yes
USE_TOOLS+=	wish:run

SUBST_CLASSES+=		wish
SUBST_MESSAGE.wish=	"Fixing a hardcoded command."
SUBST_STAGE.wish=	pre-configure
SUBST_FILES.wish=	tkdiff
SUBST_SED.wish=		-e 's,exec wish,exec ${WISH},'

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/tkdiff ${PREFIX}/bin/tkdiff4

.include "../../mk/bsd.pkg.mk"
