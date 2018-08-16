# $NetBSD: Makefile,v 1.6 2018/08/16 18:55:12 adam Exp $
#

RSYSLOG_MOD=	pgsql
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	1

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-pgsql

BUILD_DIRS+=		plugins/ompgsql

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/plugins/ompgsql/createDB.sql \
		${DESTDIR}${EGDIR}/createDB-pgsql.sql

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
