# $NetBSD: Makefile,v 1.20 2008/02/09 07:06:33 adam Exp $

PKGNAME=		unixodbc-${ODBC_BASE_VERS}
COMMENT=		ODBC 2.x/3.x driver manager

CONFLICTS+=		iodbc-[0-9]*

.include "../../databases/unixodbc/Makefile.common"

USE_TOOLS+=		flex yacc # to get libodbctxt.la
CONFIGURE_ARGS+=	--disable-gui

PLIST_SUBST+=		UNIXODBC_DRIVERS_DIR=${UNIXODBC_DRIVERS_DIR}
FILES_SUBST+=		UNIXODBC_DRIVERS_DIR=${UNIXODBC_DRIVERS_DIR}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=		${EGDIR}/odbc.ini ${PKG_SYSCONFDIR}/odbc.ini
OWN_DIRS=		${PKG_SYSCONFDIR}/ODBCDataSources

post-patch: fix-driver-installation

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/odbc.ini
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@UNIXODBC_DRIVERS_DIR@,${UNIXODBC_DRIVERS_DIR},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	${CP} ${FILESDIR}/odbcinst.ini.in ${WRKDIR}/odbc.ini

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/odbc.ini ${EGDIR}/odbc.ini

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
