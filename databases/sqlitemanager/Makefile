# $NetBSD: Makefile,v 1.6 2008/03/03 15:21:07 jlam Exp $
#

DISTNAME=		SQLiteManager-1.0.4
PKGREVISION=		2
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sqlitemanager/}

MAINTAINER=		manu@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/silsm/
COMMENT=		Web frontend for managing SQLite databases

DEPENDS+=		php>=5.0.3nb1:../../lang/php5

PKG_DESTDIR_SUPPORT=	destdir

NO_BUILD=		yes

PKG_USERS_VARS+=	APACHE_USER

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/sqlitemanager
	cd ${WRKSRC} && \
	${PAX} -rw include index.php lang left.php main.php test.sqlite theme \
	    ${DESTDIR}${PREFIX}/share/sqlitemanager
	${CHOWN} -R ${APACHE_USER} ${DESTDIR}${PREFIX}/share/sqlitemanager

.include "../../mk/bsd.pkg.mk"
