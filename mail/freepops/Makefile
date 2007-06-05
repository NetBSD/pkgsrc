# $NetBSD: Makefile,v 1.1.1.1 2007/06/05 05:56:01 schmonz Exp $
#

DISTNAME=		freepops-0.2.4
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=freepops/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.freepops.org/
COMMENT=		Extensible POP3 interface to webmail

USE_LANGUAGES=		c c++
USE_TOOLS+=		bash:run bison gmake patch tar
USE_LIBTOOL=		yes
REPLACE_BASH=		configure.sh
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_ARGS=		pkgsrc

PKG_SYSCONFSUBDIR=	freepops
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/config.lua ${PKG_SYSCONFDIR}/config.lua
OWN_DIRS+=		${VARBASE}/lib/${PKGBASE}/lua_unofficial
OWN_DIRS+=		${VARBASE}/lib/${PKGBASE}/lua_updates
OWN_DIRS+=		${VARBASE}/lib/${PKGBASE}/lua_updates/lxp
OWN_DIRS+=		${VARBASE}/lib/${PKGBASE}/lua_updates/browser
OWN_DIRS+=		${VARBASE}/lib/${PKGBASE}/lua_updates/soap

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	config.h doc/freepopsd.1 src/freepops.h
SUBST_FILES.paths+=	src/lua/freepops.lua
SUBST_SED.paths=	-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.paths+=	-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'
SUBST_SED.paths+=	-e 's|@VARBASE@|${VARBASE}|g'
SUBST_MESSAGE.paths=	Adjusting paths.

BUILD_DEFS+=		VARBASE

.include "../../mk/bsd.prefs.mk"

RCD_SCRIPTS=			freepopsd
FREEPOPSD_USER?=		freepops
FREEPOPSD_GROUP?=		freepops
PKG_GROUPS=			${FREEPOPSD_GROUP}
PKG_USERS=			${FREEPOPSD_USER}:${FREEPOPSD_GROUP}
PKG_GECOS.${FREEPOPSD_USER}=	freepopsd POP3 user
FILES_SUBST+=			FREEPOPSD_USER=${FREEPOPSD_USER:Q}
FILES_SUBST+=			FREEPOPSD_GROUP=${FREEPOPSD_GROUP:Q}

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
