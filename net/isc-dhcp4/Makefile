# $NetBSD: Makefile,v 1.5 2010/06/25 21:56:46 joerg Exp $
#

PKGNAME=	isc-dhcp-${DHVER}
PKGREVISION=	1
COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Base
SUBDIR=		includes common minires dst

PKG_DESTDIR_SUPPORT=	user-destdir

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
