# $NetBSD: Makefile,v 1.7 2009/07/17 18:00:15 adrianp Exp $

DISTNAME=	libnet-1.1.2.1
PKGNAME=	${DISTNAME:S/libnet/libnet11/}
CATEGORIES=	devel net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.packetfactory.net/libnet/
COMMENT=	C library for portable packet creation and injection

PKG_INSTALLATION_TYPES=	overwrite pkgviews
CONFLICTS=	libnet-[0-9]*

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/libnet

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/libnet11
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/libnet11

LNDOCS=		DESIGN_NOTES MIGRATION PACKET_BUILDING RAWSOCKET_NON_SEQUITUR
LNMAN=		libnet-functions.h.3 libnet-headers.h.3 libnet-macros.h.3 \
		libnet.h.3 libnet_802_1q_hdr.3 libnet_802_1x_hdr.3

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libnet11
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libnet11/html
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/libnet11
	${INSTALL_MAN_DIR} ${PREFIX}/${PKGMANDIR}/man3

	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html \
		${PREFIX}/share/doc/libnet11/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.css \
		${PREFIX}/share/doc/libnet11/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.png\
		${PREFIX}/share/doc/libnet11/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.dot\
		${PREFIX}/share/doc/libnet11/html

	${INSTALL_DATA} ${WRKSRC}/sample/*.c \
		${PREFIX}/share/examples/libnet11

.	for f in ${LNMAN}
		${INSTALL_MAN} ${WRKSRC}/doc/man/man3/${f} \
			${PREFIX}/${PKGMANDIR}/man3/${f:S/libnet/libnet11/}
.	endfor

.	for f in ${LNDOCS}
		${INSTALL_DATA} ${WRKSRC}/doc/${f} \
			${PREFIX}/share/doc/libnet11/
.	endfor

	${INSTALL_SCRIPT} ${WRKSRC}/libnet-config \
		${PREFIX}/bin/libnet11-config

.include "../../mk/bsd.pkg.mk"
