# $NetBSD: Makefile,v 1.11 2006/02/05 23:09:06 joerg Exp $
#

DISTNAME=	tclticker-1.1
PKGREVISION=	1
CATEGORIES=	finance tk
MASTER_SITES=	http://www.neosoft.com/tcl/ftparchive/sorted/apps/tclticker/1.1/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Stock-quote ticker tape application

DEPENDS+=	tk>=8.3.2:../../x11/tk

PKG_INSTALLATINO_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes
NO_BUILD=	yes

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing hardcoded paths and command names."
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	tclticker mailquote
SUBST_SED.paths=	-e 's|@PREFIX@|${PREFIX}|g'

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tclticker ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mailquote ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/tclticker
	cd ${WRKSRC}/lib && ${PAX} -rw . ${PREFIX}/share/tclticker

.include "../../mk/bsd.pkg.mk"
