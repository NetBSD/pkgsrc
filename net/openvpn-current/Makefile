# $NetBSD: Makefile,v 1.13 2005/04/11 21:46:53 tv Exp $
#

DISTNAME=	openvpn-2.0_rc1
PKGNAME=	${DISTNAME:S/_//}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openvpn/}

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://openvpn.sourceforge.net/
COMMENT=	Easy-to-use SSL VPN daemon

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
USE_OLD_DES_API=	yes

PKG_SYSCONFSUBDIR=	openvpn
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
RCD_SCRIPTS=		openvpn

CONFIGURE_ARGS+=	--enable-pthread
CONFIGURE_ARGS+=	--enable-lzo
CONFIGURE_ARGS+=	--enable-crypt
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ARGS+=	--enable-multi
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

# The configure script assumes that PTHREAD_LIBS also contains any LDFLAGS
# needed to link with -lpthread.
#
PTHREAD_LIBS+=	${PTHREAD_LDFLAGS}

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${EGDIR}/config
	cd ${WRKSRC}/sample-config-files; for file in *; do		\
		${INSTALL_DATA} $$file ${EGDIR}/config;			\
	done
	${INSTALL_DATA_DIR} ${EGDIR}/scripts
	cd ${WRKSRC}/sample-scripts; for file in *; do			\
		${INSTALL_DATA} $$file ${EGDIR}/scripts;		\
	done
	${INSTALL_DATA_DIR} ${EGDIR}/keys
	cd ${WRKSRC}/sample-keys; for file in *; do			\
		${INSTALL_DATA} $$file ${EGDIR}/keys;			\
	done

.include "../../mk/bsd.pkg.mk"
