# $NetBSD: Makefile,v 1.3 2004/12/03 19:46:51 jlam Exp $
#

DISTNAME=	openvpn-2.0_beta15
PKGNAME=	${DISTNAME:S/_//}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openvpn/}

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://openvpn.sourceforge.net/
COMMENT=	Easy-to-use SSL VPN daemon

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKG_SYSCONFSUBDIR=	openvpn

CONFIGURE_ARGS+=	--enable-pthread
CONFIGURE_ARGS+=	--enable-lzo
CONFIGURE_ARGS+=	--enable-crypt
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ARGS+=	--enable-multi
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

LIBS+=		-ldes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/openvpn
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/openvpn/config
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/openvpn/scripts
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/openvpn/keys
	${INSTALL_DATA} ${WRKSRC}/sample-config-files/* \
		${PREFIX}/share/examples/openvpn/config
	${INSTALL_DATA} ${WRKSRC}/sample-scripts/* \
		${PREFIX}/share/examples/openvpn/scripts
	${INSTALL_DATA} ${WRKSRC}/sample-keys/* \
		${PREFIX}/share/examples/openvpn/keys

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
