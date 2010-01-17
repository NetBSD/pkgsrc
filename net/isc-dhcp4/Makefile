# $NetBSD: Makefile,v 1.4 2010/01/17 12:02:32 wiz Exp $
#

PKGNAME=	isc-dhcp-${DHVER}
PKGREVISION=	1
COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Base
SUBDIR=		includes common minires dst

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}

	${INSTALL_DATA} ${WRKSRC}/README \
		${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/RELNOTES \
		${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/References.txt \
		${PREFIX}/share/doc/${PKGBASE}

.include "../../net/isc-dhcp4/Makefile.common"
.include "../../mk/bsd.pkg.mk"
