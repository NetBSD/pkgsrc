# $NetBSD: Makefile,v 1.25 2023/04/19 08:11:33 adam Exp $
#

RSYSLOG_MOD=	gnutls
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	15

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
