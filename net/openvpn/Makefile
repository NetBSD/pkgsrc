# $NetBSD: Makefile,v 1.52 2014/02/12 23:18:24 tron Exp $

DISTNAME=	${OPENVPN_DISTNAME}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${OPENVPN_MASTER_SITES}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openvpn.net/
COMMENT=	Easy-to-use SSL VPN daemon
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		grep:run
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-dependency-tracking
CONFIGURE_ARGS+=	--enable-password-save
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

USE_OLD_DES_API=	yes
TEST_TARGET=		check

PKG_SYSCONFSUBDIR=	openvpn
DATADIR=		${PREFIX}/share/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
RCD_SCRIPTS=		openvpn

INSTALLATION_DIRS+=	${EGDIR}/config
INSTALLATION_DIRS+=	${EGDIR}/keys
INSTALLATION_DIRS+=	${EGDIR}/scripts

.include "../../mk/bsd.prefs.mk"

PKG_GROUPS=		${OPENVPN_GROUP}
PKG_USERS=		${OPENVPN_USER}:${OPENVPN_GROUP}
PKG_GECOS.${OPENVPN_USER}=	OpenVPN\ server\ user

MESSAGE_SUBST+=	OPENVPN_PLUGINSDIR=${PREFIX}/${OPENVPN_PLUGINSDIR}

post-install:
	set -e; cd ${WRKSRC}/sample/sample-config-files; for file in *; do \
		${INSTALL_DATA} $$file ${DESTDIR}${EGDIR}/config;	   \
	done
	set -e; cd ${WRKSRC}/sample/sample-scripts; for file in *; do	   \
		${INSTALL_DATA} $$file ${DESTDIR}${EGDIR}/scripts;	   \
	done
	set -e; cd ${WRKSRC}/sample/sample-keys; for file in *; do	   \
		${INSTALL_DATA} $$file ${DESTDIR}${EGDIR}/keys;		   \
	done

.include "options.mk"
.include "../../net/openvpn/Makefile.common"

# OpenVPN 2.x has a shared module "plugin" architecture that allows
# inserting callbacks into the server for various tasks.
DL_AUTO_VARS=		yes
.include "../../mk/dlopen.buildlink3.mk"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
.include "../../net/solaris-tap/buildlink3.mk"
.endif
.include "../../archivers/lzo/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
