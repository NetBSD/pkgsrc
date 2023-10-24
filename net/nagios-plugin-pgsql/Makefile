# $NetBSD: Makefile,v 1.25 2023/10/24 22:10:25 wiz Exp $

PKGNAME=	nagios-plugin-pgsql-${PLUGINSVERSION}
PKGREVISION=	1
CATEGORIES=	net sysutils databases

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Nagios pgsql plugin
LICENSE=	gnu-gpl-v3

DEPENDS+=	nagios-plugins-${PLUGINSVERSION}{,nb[0-9]*}:../../net/nagios-plugins

CONFIGURE_ARGS+=	--with-pgsql=${BUILDLINK_PREFIX.pgsql-lib}

.include "../../net/nagios-plugins/Makefile.common"

BINARY_TARGET=	check_pgsql

.include "../../net/nagios-plugins/plugin.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
