# $NetBSD: Makefile,v 1.1.1.1 2005/01/20 18:04:57 adrianp Exp $

DISTNAME=	libnet-1.1.2.1
CATEGORIES=	devel net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.packetfactory.net/libnet/
COMMENT=	C library for portable packet creation and injection

CONFLICTS=	libnet-1.0.[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
WRKSRC=		${WRKDIR}/libnet

LNDOCS=		DESIGN_NOTES MIGRATION PACKET_BUILDING RAWSOCKET_NON_SEQUITUR

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libnet
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/libnet
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/libnet
	${INSTALL_MAN_DIR} ${PREFIX}/man/man3

	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html \
		${PREFIX}/share/doc/html/libnet
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.css \
		${PREFIX}/share/doc/html/libnet
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.png\
		${PREFIX}/share/doc/html/libnet
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.dot\
		${PREFIX}/share/doc/html/libnet

	${INSTALL_DATA} ${WRKSRC}/sample/*.c \
		${PREFIX}/share/examples/libnet

	${INSTALL_MAN} ${WRKSRC}/doc/man/man3/*.3 \
		${PREFIX}/man/man3

	for f in ${LNDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/doc/$$f \
			${PREFIX}/share/doc/libnet/; \
	done

.include "../../mk/bsd.pkg.mk"
