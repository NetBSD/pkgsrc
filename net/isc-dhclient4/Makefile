# $NetBSD: Makefile,v 1.4.8.1 2011/04/11 14:02:08 tron Exp $
#

PKGNAME=	isc-dhclient-${DHVER}
COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Client
BUILD_SUBDIR=	bind includes tests common omapip client
SUBDIR=		client

PKG_DESTDIR_SUPPORT=	user-destdir

CONF_FILES+=	${EGDIR}/dhclient.conf ${PKG_SYSCONFDIR}/dhclient.conf

RCD_SCRIPTS=	isc_dhclient
FILES_SUBST+=	DHCP_HOME=${DHCP_HOME}

.include "${.CURDIR}/../isc-dhcp4/options.mk"

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/client/dhclient.conf ${DESTDIR}${EGDIR}

.include "../../net/isc-dhcp4/Makefile.common"
.include "../../net/isc-dhcp4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
