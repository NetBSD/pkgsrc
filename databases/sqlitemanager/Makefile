# $NetBSD: Makefile,v 1.1.1.1 2005/01/04 13:53:31 manu Exp $
#

DISTNAME=		SQLiteManager-1.0.4
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sqlitemanager/}

MAINTAINER=		manu@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/silsm/
COMMENT=		Web frontend for managing SQLite databases

DEPENDS+=		php>=5.0.3nb1:../../lang/php5

USE_BUILDLINK3=		yes

APACHE_USER?=		www

do-build:
	# nothing

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share
	${INSTALL_DATA_DIR} ${PREFIX}/share/sqlitemanager
	cd ${WRKSRC} && \
	${PAX} -rw include index.php lang left.php main.php test.sqlite theme \
	    ${PREFIX}/share/sqlitemanager
	${CHOWN} -R ${APACHE_USER} ${PREFIX}/share/sqlitemanager

.include "../../mk/bsd.pkg.mk"
