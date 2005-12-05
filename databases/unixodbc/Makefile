# $NetBSD: Makefile,v 1.15 2005/12/05 20:50:01 rillig Exp $

PKGNAME=		unixodbc-${ODBC_BASE_VERS}
PKGREVISION=		5
COMMENT=		ODBC 2.x/3.x driver manager

CONFLICTS+=		iodbc-[0-9]*

.include "../../databases/unixodbc/Makefile.common"

USE_PKGINSTALL=		yes
USE_TOOLS+=		flex # to get libodbctxt.la
CONFIGURE_ARGS+=	--disable-gui

PLIST_SUBST+=		UNIXODBC_DRIVERS_DIR=${UNIXODBC_DRIVERS_DIR:Q}
FILES_SUBST+=		UNIXODBC_DRIVERS_DIR=${UNIXODBC_DRIVERS_DIR:Q}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=		${EGDIR}/odbcinst.ini ${PKG_SYSCONFDIR}/odbcinst.ini
CONF_FILES+=		/dev/null ${PKG_SYSCONFDIR}/odbc.ini
OWN_DIRS=		${PKG_SYSCONFDIR}/ODBCDataSources

post-patch: fix-driver-installation

pre-install:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/odbcinst.ini.in		\
		> ${WRKDIR}/odbcinst.ini

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/odbcinst.ini ${EGDIR}/odbcinst.ini

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
