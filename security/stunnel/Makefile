# $NetBSD: Makefile,v 1.80 2013/01/08 23:45:39 jym Exp $

DISTNAME=		stunnel-4.54
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.stunnel.org/stunnel/

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
PKG_HOME?=		${VARBASE}/chroot/stunnel
PKG_USERS=		${STUNNEL_USER}:${STUNNEL_GROUP}::Stunnel:${PKG_HOME}
PKG_GROUPS=		${STUNNEL_GROUP}
USER_GROUP=		${STUNNEL_USER} ${STUNNEL_GROUP}

PKG_SYSCONFSUBDIR=	stunnel
PKG_SYSCONFDIR_PERMS=	${ROOT_USER} ${STUNNEL_GROUP} 0750

OWN_DIRS=		${PKG_HOME}/certs ${PKG_HOME}/crls
OWN_DIRS_PERMS=		${PKG_HOME}/pid ${USER_GROUP} 0750
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
