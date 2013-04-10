# $NetBSD: Makefile,v 1.11 2013/04/10 11:31:26 fhajny Exp $
#

PKGNAME=	isc-dhcp-${DHVER}
PKGREVISION=	1
COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Base
BUILD_SUBDIR=	bind includes tests common # dst
SUBDIR=		includes common # dst

.include "options.mk"

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/RELNOTES \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/References.txt \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../net/isc-dhcp4/Makefile.common"
.include "../../mk/bsd.pkg.mk"
