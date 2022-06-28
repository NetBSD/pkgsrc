# $NetBSD: Makefile,v 1.37 2022/06/28 11:34:23 wiz Exp $

DISTNAME=	opendkim-2.10.3
PKGREVISION=	9
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opendkim/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://opendkim.org/
COMMENT=	Open source DKIM library, MTA filter implementation and tools
LICENSE=	sendmail-open-source-license

USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake autoreconf
USE_TOOLS+=		pkg-config perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

LDFLAGS.SunOS+=	-lsocket -lnsl

REPLACE_PERL+=	opendkim/opendkim-genkey.in

FILES_SUBST+=	DKIM_USER=${DKIM_USER} DKIM_GROUP=${DKIM_GROUP}
BUILD_DEFS+=	VARBASE DKIM_USER DKIM_GROUP

DKIM_USER?=		opendkim
DKIM_GROUP?=		opendkim
PKG_GROUPS=		${DKIM_USER}
PKG_USERS=		${DKIM_USER}:${DKIM_GROUP}
PKG_GROUPS_VARS+=	DKIM_GROUP
PKG_USERS_VARS+=	DKIM_USER
OWN_DIRS_PERMS+=	${VARBASE}/run/opendkim \
			${DKIM_USER} ${DKIM_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/db/opendkim \
			${DKIM_USER} ${DKIM_GROUP} 0700

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing default paths
SUBST_FILES.path=	opendkim/opendkim.conf.sample
SUBST_SED.path=		-e 's,/var/db/dkim,${VARBASE}/db/opendkim,g'

PKGCONFIG_OVERRIDE+=	libopendkim/opendkim.pc.in

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

PLIST_SRC+=		${PKGDIR}/PLIST

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
