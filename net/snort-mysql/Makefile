# $NetBSD: Makefile,v 1.2 2002/10/10 12:23:38 wiz Exp $
#

.include "../../net/snort/Makefile.common"

PKGNAME=        ${DISTNAME:S/-/-mysql-/}

COMMENT=        Libpcap-based packet sniffer/logger using a MySQL database

CONFLICTS+=     snort-[0-9]*
CONFLICTS+=     snort-pgsql-[0-9]*

CONFIGURE_ARGS+=--with-mysql=${BUILDLINK_PREFIX.mysql-client}

USE_BUILDLINK2=	YES

PKGDIR=         ${.CURDIR}/../../net/snort
PATCHDIR=       ${PKGDIR}/patches
DISTINFO_FILE=  ${PKGDIR}/distinfo

.include "../../mk/bsd.prefs.mk"

.if ${_USE_RPATH} == "yes"
LDFLAGS+=       -Wl,-R${BUILDLINK_PREFIX.mysql-client}/lib/mysql
.endif

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
