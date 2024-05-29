# $NetBSD: Makefile,v 1.25 2024/05/29 16:34:31 adam Exp $
#

RSYSLOG_MOD=	libgcrypt
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	19

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

#/usr/bin/ld: cannot find ../runtime/.libs/librsyslog.a: No such file or directory

MAKE_JOBS_SAFE=	no

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-libgcrypt

BUILD_DIRS=		compat grammar runtime tools

INSTALLATION_DIRS+=	bin lib/rsyslog ${PKGMANDIR}/man1

do-install:
	${INSTALL_DATA} ${WRKSRC}/runtime/.libs/lmcry_gcry.a    \
		${DESTDIR}${PREFIX}/lib/rsyslog/
	${INSTALL_LIB} ${WRKSRC}/runtime/.libs/lmcry_gcry.so    \
		${DESTDIR}${PREFIX}/lib/rsyslog/
	${INSTALL_LIB} ${WRKSRC}/runtime/.libs/lmcry_gcry.lai   \
		${DESTDIR}${PREFIX}/lib/rsyslog/lmcry_gcry.la
	${INSTALL_PROGRAM} ${WRKSRC}/tools/rscryutil		\
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tools/rscryutil.1		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
