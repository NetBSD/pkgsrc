# $NetBSD: Makefile,v 1.5 2008/05/27 19:34:30 adrianp Exp $
#

COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Base
COMPONENT=	base
SUBDIR=		common minires dst

MAN_FILES=	man5/dhcp-eval.5 man5/dhcp-options.5

INSTALLATION_DIRS=	include/isc-dhcp include/omapip \
			lib share/doc/isc-dhcp-${COMPONENT}

post-install:
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
	${CHMOD} ${LIBMODE} ${PREFIX}/lib/libdst.a

.include "../../net/isc-dhcp/Makefile.common"
.include "../../mk/bsd.pkg.mk"
