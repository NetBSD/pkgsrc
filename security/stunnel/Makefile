# $NetBSD: Makefile,v 1.131 2023/11/24 13:32:48 ryoon Exp $

DISTNAME=		stunnel-5.71
CATEGORIES=		security
MASTER_SITES=		https://www.stunnel.org/archive/5.x/

MAINTAINER=		jym@NetBSD.org
HOMEPAGE=		https://www.stunnel.org/
COMMENT=		Universal SSL tunnel
LICENSE=		gnu-gpl-v2

BUILD_DEFS+=		VARBASE PKG_SYSCONFBASE
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q}

.include "../../mk/bsd.prefs.mk"

STUNNEL_USER?=		stunnel
STUNNEL_GROUP?=		stunnel
PKG_USERS=		${STUNNEL_USER}:${STUNNEL_GROUP}
PKG_GROUPS=		${STUNNEL_GROUP}
USER_GROUP=		${STUNNEL_USER} ${STUNNEL_GROUP}

PKG_GECOS.${STUNNEL_USER}?=	Stunnel
PKG_HOME.${STUNNEL_USER}?=	${VARBASE}/chroot/stunnel

PKG_SYSCONFSUBDIR=	stunnel
PKG_SYSCONFDIR_PERMS=	${REAL_ROOT_USER} ${STUNNEL_GROUP} 0750

OWN_DIRS=		${PKG_HOME.${STUNNEL_USER}}/certs ${PKG_HOME.${STUNNEL_USER}}/crls
OWN_DIRS_PERMS=		${PKG_HOME.${STUNNEL_USER}}/pid ${USER_GROUP} 0750
CONF_FILES+=		${PREFIX}/share/examples/stunnel/stunnel.conf-sample \
			    ${PKG_SYSCONFDIR}/stunnel.conf

RCD_SCRIPTS=		stunnel

REPLACE_PERL+=		src/stunnel3.in
USE_TOOLS+=		perl:run

SUBST_CLASSES+=		stunnel
SUBST_MESSAGE.stunnel=	Fix user and group
SUBST_STAGE.stunnel=	pre-configure
SUBST_FILES.stunnel=	tools/stunnel.conf-sample.in
SUBST_VARS.stunnel=	STUNNEL_USER STUNNEL_GROUP

TEST_TARGET=		check

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
