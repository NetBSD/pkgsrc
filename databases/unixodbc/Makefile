# $NetBSD: Makefile,v 1.11 2004/04/25 01:11:11 xtraeme Exp $

PKGNAME=		unixodbc-${ODBC_BASE_VERS}
PKGREVISION=		2
COMMENT=		ODBC 2.x/3.x driver manager

CONFLICTS+=		iodbc-[0-9]*

.include "../../databases/unixodbc/Makefile.common"

USE_PKGINSTALL=		yes
CONFIGURE_ARGS+=	--disable-gui

PLIST_SUBST+=		UNIXODBC_DRIVERS_DIR=${UNIXODBC_DRIVERS_DIR}
FILES_SUBST+=		UNIXODBC_DRIVERS_DIR=${UNIXODBC_DRIVERS_DIR}

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
