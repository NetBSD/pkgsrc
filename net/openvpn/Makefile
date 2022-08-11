# $NetBSD: Makefile,v 1.93 2022/08/11 06:41:58 wiz Exp $

DISTNAME=	${OPENVPN_DISTNAME}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${OPENVPN_MASTER_SITES}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://openvpn.net/
COMMENT=	Easy-to-use SSL VPN daemon
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		grep:run pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-dependency-tracking
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		ac_cv_prog_RST2HTML=
CONFIGURE_ENV+=		ac_cv_prog_RST2MAN=

TEST_TARGET=		check

PKG_SYSCONFSUBDIR=	openvpn
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
RCD_SCRIPTS=		openvpn

INSTALLATION_DIRS+=	${EGDIR}/config
INSTALLATION_DIRS+=	${EGDIR}/keys
INSTALLATION_DIRS+=	${EGDIR}/scripts

SMF_METHODS=	openvpn

.include "../../mk/bsd.prefs.mk"

PKG_GROUPS=		${OPENVPN_GROUP}
PKG_USERS=		${OPENVPN_USER}:${OPENVPN_GROUP}
PKG_GECOS.${OPENVPN_USER}= OpenVPN\ server\ user

MESSAGE_SUBST+=	OPENVPN_PLUGINSDIR=${PREFIX}/${OPENVPN_PLUGINSDIR}

post-install:
	${RUN} cd ${WRKSRC}/sample/sample-config-files; for file in *; do \
		${INSTALL_DATA} $$file ${DESTDIR}${EGDIR}/config;	   \
	done
	${RUN} cd ${WRKSRC}/sample/sample-scripts; for file in *; do	   \
		${INSTALL_DATA} $$file ${DESTDIR}${EGDIR}/scripts;	   \
	done
	${RUN} cd ${WRKSRC}/sample/sample-keys; for file in *; do	   \
		${INSTALL_DATA} $$file ${DESTDIR}${EGDIR}/keys;		   \
	done

.include "options.mk"
.include "../../net/openvpn/Makefile.common"

# OpenVPN 2.x has a shared module "plugin" architecture that allows
# inserting callbacks into the server for various tasks.
DL_AUTO_VARS=		yes
.include "../../mk/dlopen.buildlink3.mk"

.if ${OPSYS} == "SunOS"
.include "../../net/solaris-tap/buildlink3.mk"
.endif
.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
