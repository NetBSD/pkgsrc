# $NetBSD: Makefile,v 1.1.1.1 2004/02/10 12:39:17 wulf Exp $

DISTNAME=	openvpn-1.5.0
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openvpn/}

MAINTAINER=	packages@nNetBSD.org
HOMEPAGE=	http://openvpn.sourceforge.net/
COMMENT=	Easy-to-use, robust, and highly configurable VPN over UDP

USE_BUILDLINK2=		YES
#USE_PKGINSTALL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-ssl-headers=${SSLBASE}/include/openssl
CONFIGURE_ARGS+=	--with-ssl-lib=${SSLBASE}/lib
CONFIGURE_ARGS+=	--with-lzo-headers=${BUILDLINK_PREFIX.liblzo}/include
CONFIGURE_ARGS+=	--with-lzo-lib=${BUILDLINK_PREFIX.liblzo}/lib

EGDIR=			${PREFIX}/share/examples/openvpn

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}/sample-config-files
	${INSTALL_DATA}	${WRKSRC}/sample-config-files/* ${EGDIR}/sample-config-files
	${INSTALL_DATA_DIR} ${EGDIR}/sample-keys
	${INSTALL_DATA}	${WRKSRC}/sample-keys/* ${EGDIR}/sample-keys
	${INSTALL_DATA_DIR} ${EGDIR}/sample-scripts
	${INSTALL_DATA}	${WRKSRC}/sample-scripts/* ${EGDIR}/sample-scripts

.include "../../archivers/liblzo/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
