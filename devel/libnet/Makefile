# $NetBSD: Makefile,v 1.26 2005/09/28 20:52:19 rillig Exp $
#

DISTNAME=	libnet-1.0.2a
CATEGORIES=	devel net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/deprecated/

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.packetfactory.net/libnet/
COMMENT=	C library for portable packet creation and injection

PKG_INSTALLATION_TYPES=	overwrite pkgviews
CONFLICTS=	libnet-1.1.[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME:C/l/L/}

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBNET_CONFIG_CFLAGS="-I${PREFIX}/include" \
		LIBNET_CONFIG_LIBS="${LDFLAGS}"

INSTALLATION_DIRS=	bin lib share/examples

post-extract:
	${CHMOD} -R a+r ${WRKSRC}/doc

.include "../../mk/bsd.pkg.mk"
