# $NetBSD: backend.mk,v 1.1 2025/06/30 11:00:50 jperkin Exp $
# used by net/powerdns-geoip/Makefile
# used by net/powerdns-ldap/Makefile
# used by net/powerdns-mysql/Makefile
# used by net/powerdns-odbc/Makefile
# used by net/powerdns-pgsql/Makefile

.include "../../net/powerdns/Makefile.common"

DEPENDS+=		powerdns>=${PDNS_VERSION}:../../net/powerdns

DISTINFO_FILE=		${.CURDIR}/../../net/powerdns/distinfo
PATCHDIR=		${.CURDIR}/../../net/powerdns/patches

CONFIGURE_ARGS+=	--disable-lua-records
CONFIGURE_ARGS+=	--disable-pdns_server
CONFIGURE_ARGS+=	--with-modules=""

BUILD_DIRS=		modules

# These are required by configure, but not used by the modules
BUILDLINK_DEPMETHOD.boost-libs=		build
BUILDLINK_DEPMETHOD.openssl=		build
