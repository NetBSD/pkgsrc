# $NetBSD: Makefile,v 1.15 2003/10/29 18:39:45 cube Exp $
#

DISTNAME=	libnet-1.0.1b
PKGREVISION=	3
WRKSRC=		${WRKDIR}/${DISTNAME:C/l/L/}
CATEGORIES=	devel net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.packetfactory.net/libnet/
COMMENT=	C library for portable packet creation and injection

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
