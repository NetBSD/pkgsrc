# $NetBSD: Makefile,v 1.4 2008/04/07 17:23:40 joerg Exp $
#

COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Base
COMPONENT=	base
PKGREVISION=	1
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

.include "../../net/isc-dhcp/Makefile.common"
.include "../../mk/bsd.pkg.mk"
