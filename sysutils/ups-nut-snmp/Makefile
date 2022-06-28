# $NetBSD: Makefile,v 1.12 2022/06/28 11:36:06 wiz Exp $

PKGREVISION= 1
.include "../../sysutils/ups-nut/Makefile.common"

PKGNAME=		${DISTNAME:S/nut/ups-nut-snmp/}
COMMENT=		Network UPS Tools SNMP driver

DEPENDS+=		ups-nut-2.*:../../sysutils/ups-nut

BUILD_DEFS+=		NUT_STATEDIR

INSTALLATION_DIRS+=	${PREFIX}/libexec/nut
INSTALLATION_DIRS+=	${PREFIX}/${PKGMANDIR}/man8

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--with-snmp --with-drvpath=${NUT_DRVDIR:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/drivers/snmp-ups \
	    ${DESTDIR}${PREFIX}/libexec/nut/
	${INSTALL_MAN} ${WRKSRC}/docs/man/snmp-ups.8 \
	    ${DESTDIR}${PREFIX}//${PKGMANDIR}/man8/

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
