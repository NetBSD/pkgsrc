# $NetBSD: Makefile,v 1.25 2016/03/05 11:28:49 jperkin Exp $

DISTNAME=	opendkim-2.10.1
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opendkim/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://opendkim.org/
COMMENT=	Open source DKIM library, MTA filter implementation and tools
LICENSE=	sendmail-open-source-license

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

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

PLIST_SRC+=		${PKGDIR}/PLIST

BUILDLINK_API_DEPENDS.openssl+=		openssl>=0.9.8
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_API_DEPENDS.libmilter+=	libmilter>=8.13.0
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
