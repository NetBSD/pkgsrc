# $NetBSD: Makefile,v 1.1.1.1 2002/07/12 16:55:40 agc Exp $
#

.include "../../net/snort/Makefile.common"

PKGNAME=        ${DISTNAME:S/-/-mysql-/}

COMMENT=        Libpcap-based packet sniffer/logger using a MySQL database

CONFLICTS+=     snort-[0-9]*
CONFLICTS+=     snort-pgsql-[0-9]*

CONFIGURE_ARGS+=--with-mysql=${BUILDLINK_DIR}

PKGDIR=         ${.CURDIR}/../../net/snort
PATCHDIR=       ${PKGDIR}/patches
DISTINFO_FILE=  ${PKGDIR}/distinfo

.include "../../mk/bsd.prefs.mk"

.if ${_USE_RPATH} == "yes"
LDFLAGS+=       -Wl,-R${LOCALBASE}/lib/mysql
.endif

.include "../../databases/mysql-client/buildlink.mk"
.include "../../net/libpcap/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
