# $NetBSD: Makefile,v 1.2 2001/11/19 16:23:09 jlam Exp $

PKGNAME=		unixodbc-${ODBC_VERS}
ODBC_PKG_VERS=		# empty
COMMENT=		ODBC 2.x/3.x driver manager

CONFLICTS+=		iodbc-[0-9]*
USE_BUILDLINK_ONLY=	YES

.include "../../databases/unixodbc/Makefile.common"

CONFIGURE_ARGS+=	--disable-gui

PLIST_SUBST+=		UNIXODBC_DRIVERS_DIR=${UNIXODBC_DRIVERS_DIR}
FILES_SUBST+=		UNIXODBC_DRIVERS_DIR=${UNIXODBC_DRIVERS_DIR}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=		${EGDIR}/odbcinst.ini ${CONFDIR}/odbcinst.ini
CONF_FILES+=		/dev/null ${CONFDIR}/odbc.ini
OWN_DIRS=		${CONFDIR}/ODBCDataSources

post-patch: fix-driver-installation

pre-install:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/odbcinst.ini.in		\
		> ${WRKDIR}/odbcinst.ini
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/odbcinst.ini ${EGDIR}/odbcinst.ini
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../devel/readline/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
