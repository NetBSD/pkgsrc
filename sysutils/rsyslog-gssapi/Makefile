# $NetBSD: Makefile,v 1.28 2024/11/01 12:54:31 wiz Exp $
#

RSYSLOG_MOD=	gssapi
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	22

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

KRB5_ACCEPTED=	mit-krb5

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-gssapi-krb5

BUILD_DIRS=		. plugins/imgssapi plugins/omgssapi
INSTALL_DIRS=		plugins/imgssapi plugins/omgssapi

post-install:
	${INSTALL_DATA} ${WRKSRC}/runtime/.libs/lmgssutil.a    \
		${DESTDIR}${PREFIX}/lib/rsyslog/
	${INSTALL_LIB} ${WRKSRC}/runtime/.libs/lmgssutil.so    \
		${DESTDIR}${PREFIX}/lib/rsyslog/
	${INSTALL_LIB} ${WRKSRC}/runtime/.libs/lmgssutil.lai   \
		${DESTDIR}${PREFIX}/lib/rsyslog/lmgssutil.la

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
