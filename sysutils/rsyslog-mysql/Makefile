# $NetBSD: Makefile,v 1.18 2021/09/29 19:01:22 adam Exp $
#

RSYSLOG_MOD=	mysql
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	13

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-mysql

BUILD_DIRS=		plugins/ommysql

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/plugins/ommysql/createDB.sql \
		${DESTDIR}${EGDIR}/createDB-mysql.sql

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
