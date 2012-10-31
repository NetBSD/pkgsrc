# $NetBSD: Makefile,v 1.24 2012/10/31 11:19:50 asau Exp $
#

DISTNAME=	tkdiff-4.1.4-unix
PKGNAME=	${DISTNAME:S/-unix//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tkdiff/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/tkdiff/
COMMENT=	Graphical 2-way diff/merge tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILD=	yes
NO_CONFIGURE=	yes
USE_TOOLS+=	wish:run

SUBST_CLASSES+=		wish
SUBST_MESSAGE.wish=	Fixing a hardcoded command.
SUBST_STAGE.wish=	pre-configure
SUBST_FILES.wish=	tkdiff
SUBST_SED.wish=		-e 's,exec wish,exec ${WISH},'

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkdiff ${DESTDIR}${PREFIX}/bin/tkdiff4

.include "../../mk/bsd.pkg.mk"
