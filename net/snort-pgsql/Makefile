# $NetBSD: Makefile,v 1.3 2002/07/15 14:41:51 wiz Exp $
#

.include "../snort/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-pgsql-/}

COMMENT=	Libpcap-based packet sniffer/logger using a PostgreSQL database

CONFLICTS+=	snort-[0-9]*

CONFIGURE_ARGS+=--with-postgresql=${BUILDLINK_DIR}

PATCHDIR=	${.CURDIR}/../snort/patches
DISTINFO_FILE=	${.CURDIR}/../snort/distinfo

.include "../../databases/postgresql-lib/buildlink.mk"
.include "../../net/libpcap/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
