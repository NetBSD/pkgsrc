# $NetBSD: Makefile,v 1.16 2004/01/20 12:13:28 agc Exp $
#

DISTNAME=	libnet-1.0.1b
PKGREVISION=	3
CATEGORIES=	devel net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.packetfactory.net/libnet/
COMMENT=	C library for portable packet creation and injection

WRKSRC=		${WRKDIR}/${DISTNAME:C/l/L/}
USE_BUILDLINK2= # defined

USE_LIBTOOL=	# defined
GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	LIBNET_CONFIG_CFLAGS="-I${PREFIX}/include" \
		LIBNET_CONFIG_LIBS="${LDFLAGS}"

post-extract:
	${CHMOD} -R a+r ${WRKSRC}/doc

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/libnet
	@cd ${WRKSRC}/doc/html && ${PAX} -rw *.html *.gif */*.c	\
		${PREFIX}/share/doc/html/libnet
	@${LN} -s ${PREFIX}/share/doc/html/libnet/examples \
		${PREFIX}/share/examples/libnet

.include "../../mk/bsd.pkg.mk"
