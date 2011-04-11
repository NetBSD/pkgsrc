# $NetBSD: Makefile,v 1.6.6.1 2011/04/11 14:02:08 tron Exp $
#

PKGNAME=	isc-dhcp-${DHVER}
COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Base
BUILD_SUBDIR=	bind includes tests common # dst
SUBDIR=		includes common # dst

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
