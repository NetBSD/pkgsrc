# $NetBSD: Makefile,v 1.1.1.1 2007/12/12 20:02:08 adrianp Exp $
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

.include "../../wip/isc-dhcp/Makefile.common"
.include "../../mk/bsd.pkg.mk"
