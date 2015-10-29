# $NetBSD: Makefile,v 1.1 2015/10/29 16:34:14 fhajny Exp $

SYSLOG_MOD=		json
SYSLOG_MOD_TARGET=	json-plugin
COMMENT=		Syslog-ng JSON module

.include "../../sysutils/syslog-ng/Makefile.module"

CONFIGURE_ARGS+=	--with-jsonc=${BUILDLINK_PREFIX.jsonc}

.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
