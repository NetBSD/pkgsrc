# $NetBSD: Makefile,v 1.5 2001/12/03 08:09:06 jlam Exp $

PKGNAME=		unixodbc-${ODBC_BASE_VERS}
COMMENT=		ODBC 2.x/3.x driver manager

CONFLICTS+=		iodbc-[0-9]*
USE_BUILDLINK_ONLY=	YES

.include "../../databases/unixodbc/Makefile.common"

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

.include "../../devel/readline/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
