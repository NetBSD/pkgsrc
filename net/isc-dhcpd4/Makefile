# $NetBSD: Makefile,v 1.4 2010/06/25 21:56:46 joerg Exp $
#

PKGNAME=	isc-dhcpd-${DHVER}
COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Server
SUBDIR=		omapip dhcpctl server

PKG_DESTDIR_SUPPORT=	user-destdir

CONF_FILES+=	${EGDIR}/dhcpd.conf ${PKG_SYSCONFDIR}/dhcpd.conf
RCD_SCRIPTS=	isc_dhcpd
FILES_SUBST+=	DHCP_HOME=${DHCP_HOME}

.include "${.CURDIR}/../isc-dhcp4/options.mk"

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/server/dhcpd.conf ${DESTDIR}${EGDIR}

.include "../../net/isc-dhcp4/Makefile.common"
.include "../../net/isc-dhcp4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
