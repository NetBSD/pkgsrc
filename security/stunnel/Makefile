# $NetBSD: Makefile,v 1.88 2014/02/12 23:18:37 tron Exp $

DISTNAME=		stunnel-4.56
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.stunnel.org/downloads/

MAINTAINER=		jym@NetBSD.org
HOMEPAGE=		http://www.stunnel.org/
COMMENT=		Universal SSL tunnel
LICENSE=		gnu-gpl-v2

BUILD_DEFS+=		VARBASE
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
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

SUBST_CLASSES+=		chroot
SUBST_MESSAGE.chroot=	Fix chroot path
SUBST_STAGE.chroot=	pre-configure
SUBST_FILES.chroot=	tools/stunnel.conf-sample.in
SUBST_SED.chroot+=	-e 's|@prefix@/var/lib|@localstatedir@/chroot|'

SUBST_CLASSES+=		stunnel
SUBST_MESSAGE.stunnel=	Fix user, group and pid
SUBST_STAGE.stunnel=	post-configure
SUBST_FILES.stunnel=	tools/stunnel.conf-sample
SUBST_SED.stunnel=	-e 's|setuid = nobody|setuid = ${STUNNEL_USER}|'
SUBST_SED.stunnel+=	-e 's|setgid = nogroup|setgid = ${STUNNEL_GROUP}|'
SUBST_SED.stunnel+=	-e 's|pid = /stunnel.pid|pid = /pid/stunnel.pid|'

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
