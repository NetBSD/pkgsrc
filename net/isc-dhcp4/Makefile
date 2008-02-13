# $NetBSD: Makefile,v 1.1.1.1 2008/02/13 22:03:58 adrianp Exp $
#

COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Base
COMPONENT=	base
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
