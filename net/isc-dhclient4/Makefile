# $NetBSD: Makefile,v 1.9 2014/02/09 04:34:31 taca Exp $
#

PKGNAME=	isc-dhclient-${DHVER}
COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Client
BUILD_SUBDIR=	bind includes tests common omapip client
SUBDIR=		client

CONF_FILES+=	${EGDIR}/dhclient.conf ${PKG_SYSCONFDIR}/dhclient.conf

RCD_SCRIPTS=	isc_dhclient
FILES_SUBST+=	DHCP_HOME=${DHCP_HOME}

.include "${.CURDIR}/../isc-dhcp4/options.mk"

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/client/dhclient.conf.example \
		${DESTDIR}${EGDIR}/dhclient.conf

.include "../../net/isc-dhcp4/Makefile.common"
.include "../../net/isc-dhcp4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
