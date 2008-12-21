# $NetBSD: Makefile,v 1.2 2008/12/21 21:24:08 adrianp Exp $
#

COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Base
COMPONENT=	base
PKGREVISION=	1
SUBDIR=		includes common minires dst

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/isc-dhcp-${COMPONENT}

	${INSTALL_DATA} ${WRKSRC}/README \
		${PREFIX}/share/doc/isc-dhcp-${COMPONENT}
	${INSTALL_DATA} ${WRKSRC}/RELNOTES \
		${PREFIX}/share/doc/isc-dhcp-${COMPONENT}
	${INSTALL_DATA} ${WRKSRC}/doc/References.txt \
		${PREFIX}/share/doc/isc-dhcp-${COMPONENT}

.include "../../net/isc-dhcp4/Makefile.common"
.include "../../mk/bsd.pkg.mk"
