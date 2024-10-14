# $NetBSD: Makefile,v 1.1 2024/10/14 21:12:54 nia Exp $

DISTNAME=	ngircd-27
CATEGORIES=	chat
MASTER_SITES=	https://arthur.barton.de/pub/ngircd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ngircd.barton.de/
COMMENT=	Free, portable and lightweight IRC server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

RCD_SCRIPTS+=	ngircd

CONF_FILES+=	${PREFIX}/share/examples/ngircd/sample-ngircd.conf \
		${PKG_SYSCONFDIR}/ngircd.conf

BUILD_DEFS+=	VARBASE

.include "../../mk/bsd.prefs.mk"

NGIRCD_USER?=	ngircd
NGIRCD_GROUP?=	ngircd

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	pre-configure
SUBST_FILES.vars=	doc/sample-ngircd.conf.tmpl
SUBST_VARS.vars=	VARBASE
SUBST_VARS.vars+=	NGIRCD_USER
SUBST_VARS.vars+=	NGIRCD_GROUP

PKG_USERS_VARS+=	NGIRCD_USER
PKG_GROUPS_VARS+=	NGIRCD_GROUP

PKG_GROUPS=		${NGIRCD_GROUP}
PKG_USERS=		${NGIRCD_USER}:${NGIRCD_GROUP}

INSTALLATION_DIRS+=	share/examples/ngircd

OWN_DIRS_PERMS+=	${VARBASE}/run/ngircd ${NGIRCD_USER} ${NGIRCD_GROUP} 0755

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/doc/ngircd/sample-ngircd.conf \
		${DESTDIR}${PREFIX}/share/examples/ngircd/sample-ngircd.conf

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
