# $NetBSD: Makefile,v 1.8 2004/07/24 22:45:15 recht Exp $
#

.include "../../mail/ezmlm/Makefile.common"

DISTNAME=		ezmlm-idx-0.421
SITES_${DISTNAME}.tar.gz=	http://www.ezmlm.org/archive/0.421/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.ezmlm.org/
COMMENT=		ezmlm with enhancements by third parties

CONFLICTS=		ezmlm-[0-9]*

DISTFILES+=		${EZMLM_VERS}.tar.gz
PLIST_SRC+=		PLIST.idx

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

# ezmlm-idx is a modification of the ezmlm source.
RESTRICTED=		"modified source and binaries may not be distributed"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

USE_PKGINSTALL=		YES

PKG_SYSCONFSUBDIR=	ezmlm
CFLAGS+=		-DPKG_SYSCONFDIR=\"\\\"${PKG_SYSCONFDIR}\"\\\"

EGDIR=			${PREFIX}/share/examples/ezmlm-idx
CONF_FILES=		${EGDIR}/ezcgirc ${PKG_SYSCONFDIR}/ezcgirc
CONF_FILES+=		${EGDIR}/ezmlmrc ${PKG_SYSCONFDIR}/ezmlmrc

INSTALLATION_DIRS=	bin man man/man1 man/man5 man/cat1 man/cat5
INSTALLATION_DIRS+=	share/examples/ezmlm-idx

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		EZMLM_IDX_USE_MYSQL EZMLM_IDX_USE_PGSQL

.if !empty(EZMLM_IDX_USE_MYSQL:M[yY][eE][sS])
.include "../../databases/mysql-client/buildlink3.mk"
post-configure:
	${ECHO} -I${BUILDLINK_PREFIX.mysql-client}/include/mysql > ${WRKSRC}/sub_mysql/conf-sqlcc
	${ECHO} -L${BUILDLINK_PREFIX.mysql-client}/lib/mysql -Wl,-R${BUILDLINK_PREFIX.mysql-client}/lib/mysql -lmysqlclient > ${WRKSRC}/sub_mysql/conf-sqlld
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} mysql
.endif

.if !empty(EZMLM_IDX_USE_PGSQL:M[yY][eE][sS])
.include "../../mk/pgsql.buildlink3.mk"
post-configure:
	${ECHO} -I${PGSQL_PREFIX}/include > ${WRKSRC}/sub_pgsql/conf-sqlcc
	${ECHO} -L${PGSQL_PREFIX}/lib -Wl,-R${PGSQL_PREFIX}/lib -lpq > ${WRKSRC}/sub_pgsql/conf-sqlld
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} pgsql
.endif

post-extract:
	@${MV} ${WRKSRC}/* ${WRKDIR}/${EZMLM_VERS}
	@${RMDIR} ${WRKSRC}
	@${MV} ${WRKDIR}/${EZMLM_VERS} ${WRKSRC}

pre-patch:
	@cd ${WRKSRC}; ${PATCH} ${PATCH_DIST_ARGS} < idx.patch

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ezcgirc ${EGDIR}/ezcgirc
	${INSTALL_DATA} ${WRKSRC}/ezmlmrc ${EGDIR}/ezmlmrc
	${INSTALL_DATA} ${WRKSRC}/ezmlmglrc ${EGDIR}/ezmlmglrc
	${INSTALL_DATA} ${WRKSRC}/ezmlmsubrc ${EGDIR}/ezmlmsubrc

.include "../../mk/bsd.pkg.mk"
