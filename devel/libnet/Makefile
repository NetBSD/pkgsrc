# $NetBSD: Makefile,v 1.18 2004/04/25 05:35:44 minskim Exp $
#

DISTNAME=	libnet-1.0.1b
PKGREVISION=	3
CATEGORIES=	devel net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.packetfactory.net/libnet/
COMMENT=	C library for portable packet creation and injection

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${DISTNAME:C/l/L/}
USE_BUILDLINK3= yes

USE_LIBTOOL=	# defined
GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	LIBNET_CONFIG_CFLAGS="-I${PREFIX}/include" \
		LIBNET_CONFIG_LIBS="${LDFLAGS}"

INSTALLATION_DIRS=	bin share/examples

post-extract:
	${CHMOD} -R a+r ${WRKSRC}/doc

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/libnet
	@cd ${WRKSRC}/doc/html && ${PAX} -rw *.html *.gif */*.c	\
		${PREFIX}/share/doc/html/libnet
	@${LN} -s ${PREFIX}/share/doc/html/libnet/examples \
		${PREFIX}/share/examples/libnet

.include "../../mk/bsd.pkg.mk"
