# $NetBSD: Makefile,v 1.5 2016/10/13 15:17:28 fhajny Exp $

COLLECTD_PACKAGE=	postgresql

PKGNAME=		${DISTNAME:S/collectd/collectd-${COLLECTD_PACKAGE}${PGSQL_VERSION}/}
COMMENT=		Statistics collection daemon - postgresql plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libpq=${PGSQL_PREFIX}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
