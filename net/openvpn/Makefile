# $NetBSD: Makefile,v 1.5 2004/10/03 00:17:57 tv Exp $

DISTNAME=	openvpn-1.5.0
PKGREVISION=	2
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openvpn/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://openvpn.sourceforge.net/
COMMENT=	Easy-to-use, robust, and highly configurable VPN over UDP

USE_BUILDLINK3=		YES
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

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
