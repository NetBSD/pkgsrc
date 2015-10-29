# $NetBSD: Makefile,v 1.1 2015/10/29 16:34:14 fhajny Exp $

SYSLOG_MOD=		mongodb
SYSLOG_MOD_DIR=		afmongodb
COMMENT=		Syslog-ng MongoDB module

.include "../../sysutils/syslog-ng/Makefile.module"

CONFIGURE_ARGS+=	--with-libmongo-client=system

.include "../../databases/libmongo-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
