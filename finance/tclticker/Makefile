# $NetBSD: Makefile,v 1.17 2012/10/03 16:10:13 asau Exp $
#

DISTNAME=	tclticker-1.1
PKGREVISION=	1
CATEGORIES=	finance tk
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Stock-quote ticker tape application

DEPENDS+=	tk>=8.3.2:../../x11/tk

USE_TOOLS+=	pax

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes
NO_BUILD=	yes

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths and command names.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	tclticker mailquote
SUBST_SED.paths=	-e 's|@PREFIX@|${PREFIX}|g'

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC:Q}/tclticker ${DESTDIR}${PREFIX:Q}/bin
	${INSTALL_SCRIPT} ${WRKSRC:Q}/mailquote ${DESTDIR}${PREFIX:Q}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX:Q}/share/tclticker
	cd ${WRKSRC:Q}/lib && pax -rw . ${DESTDIR}${PREFIX:Q}/share/tclticker

.include "../../mk/bsd.pkg.mk"
