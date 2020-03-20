# $NetBSD: Makefile,v 1.19 2020/03/20 11:58:07 nia Exp $

DISTNAME=		gofish-1.2
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gofish/}

MAINTAINER=		esg@sdf.lonestar.org
HOMEPAGE=		http://gofish.sourceforge.net/
COMMENT=		Gopher server
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/gofish
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-gopheruser=${GOPHER_USER}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
BUILD_DEFS+=		VARBASE

EGDIR=			${PREFIX}/share/examples/gofish
RUNTIMEDIR=		${VARBASE}/gopher

.include "../../mk/bsd.prefs.mk"

GOPHER_USER?=		gopher
GOPHER_GROUP?=		gopher
PKG_GROUPS=		${GOPHER_GROUP}
PKG_USERS=		${GOPHER_USER}:${GOPHER_GROUP}
PKG_GROUPS_VARS+=	GOPHER_GROUP
PKG_USERS_VARS+=	GOPHER_USER

RCD_SCRIPTS=		gopherd

OWN_DIRS_PERMS=		${RUNTIMEDIR} ${GOPHER_USER} ${GOPHER_GROUP} 0750

.for file in gofish.conf gofish-www.conf
CONF_FILES+=		${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file}
.endfor

FILES_SUBST+=		RUNTIMEDIR=${RUNTIMEDIR}
FILES_SUBST+=		PKG_USERS=${PKG_USERS:Q}

SUBST_CLASSES+=		user
SUBST_STAGE.user=	pre-configure
SUBST_MESSAGE.user=	Fixing name of gopher user in files.
SUBST_FILES.user=	gofish.conf
SUBST_SED.user=		-e "s/;user = gopher/user = ${GOPHER_USER}/g"

INSTALLATION_DIRS=	share/examples/gofish share/doc/gofish

post-install:
	${INSTALL_DATA} ${WRKSRC}/gofish.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/gofish-www.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/Configure_GoFish ${DESTDIR}${PREFIX}/share/doc/gofish

.include "../../mk/bsd.pkg.mk"
