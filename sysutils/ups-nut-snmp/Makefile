# $NetBSD: Makefile,v 1.1.1.1 2006/08/16 13:30:35 ghen Exp $

.include "../../sysutils/ups-nut/Makefile.common"

PKGNAME=		${DISTNAME:S/nut/ups-nut-snmp/}
COMMENT=		Network UPS Tools SNMP driver

DEPENDS+=		ups-nut-2.*:../../sysutils/ups-nut

BUILD_TARGET=		all snmp
INSTALL_TARGET=		install-snmp

BUILD_DEFS+=		NUT_STATEDIR

CONFIGURE_ARGS+=	--with-drvpath=${NUT_DRVDIR:Q}

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
