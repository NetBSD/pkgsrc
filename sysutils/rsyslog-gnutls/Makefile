# $NetBSD: Makefile,v 1.30 2024/11/01 00:53:44 wiz Exp $
#

RSYSLOG_MOD=	gnutls
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	20

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-gnutls

BUILD_DIRS=		compat runtime

INSTALLATION_DIRS+=	lib/rsyslog

do-install:
	${INSTALL_LIB} ${WRKSRC}/runtime/.libs/lmnsd_gtls.so	\
		${DESTDIR}${PREFIX}/lib/rsyslog/
	${INSTALL_LIB} ${WRKSRC}/runtime/.libs/lmnsd_gtls.lai	\
		${DESTDIR}${PREFIX}/lib/rsyslog/lmnsd_gtls.la
	${INSTALL_DATA} ${WRKSRC}/runtime/.libs/lmnsd_gtls.a	\
		${DESTDIR}${PREFIX}/lib/rsyslog/

.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
