# $NetBSD: Makefile,v 1.2 2007/12/13 02:54:49 taca Exp $
#

COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Base
COMPONENT=	base
SUBDIR=		common minires dst

MAN_FILES=	man5/dhcp-eval.5 man5/dhcp-options.5

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/isc-dhcp-${COMPONENT}
	${INSTALL_DATA_DIR} ${PREFIX}/include/isc-dhcp
	${INSTALL_DATA_DIR} ${PREFIX}/include/omapip

	${INSTALL_DATA} ${WRKSRC}/README \
		${PREFIX}/share/doc/isc-dhcp-${COMPONENT}
	${INSTALL_DATA} ${WRKSRC}/RELNOTES \
		${PREFIX}/share/doc/isc-dhcp-${COMPONENT}
	${INSTALL_DATA} ${WRKSRC}/doc/References.txt \
		${PREFIX}/share/doc/isc-dhcp-${COMPONENT}
	${INSTALL_DATA} ${WRKSRC}/includes/isc-dhcp/*.h \
		${PREFIX}/include/isc-dhcp
	${INSTALL_DATA} ${WRKSRC}/includes/omapip/*.h \
		${PREFIX}/include/omapip
	${INSTALL_LIB} \
		${WRKSRC}/work.`${WRKSRC}/configure --print-sysname`/dst/*.a \
		${PREFIX}/lib

.include "../../net/isc-dhcp/Makefile.common"
.include "../../mk/bsd.pkg.mk"
