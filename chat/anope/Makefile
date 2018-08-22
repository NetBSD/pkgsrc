# $NetBSD: Makefile,v 1.21 2018/08/22 09:43:00 wiz Exp $

DISTNAME=	anope-1.7.21
PKGREVISION=	9
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=anope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.anope.org/
COMMENT=	Set of Services for IRC networks

PKG_DESTDIR_SUPPORT=	destdir

GNU_CONFIGURE=	YES
PTHREAD_OPTS+=	require
USE_TOOLS+=	gmake perl:run
ANOPE_USER=	anope
ANOPE_GROUP=	anope
RCD_SCRIPTS=	anope
FILES_SUBST+=	ANOPE_USER=${ANOPE_USER}
FILES_SUBST+=	ANOPE_GROUP=${ANOPE_GROUP}

USERGROUP_PHASE=	pre-install
PKG_USERS_VARS+=	ANOPE_USER
PKG_GROUPS_VARS+=	ANOPE_GROUP

.include "../../mk/bsd.prefs.mk"

PKG_USERS=	${ANOPE_USER}:${ANOPE_GROUP}
PKG_HOME.${ANOPE_USER}=		${PREFIX}/lib/anope
PKG_GROUPS=	${ANOPE_GROUP}
MAKE_ENV+=	RUNGROUP=${ANOPE_GROUP}
OWN_DIRS_PERMS+=	${PREFIX}/lib/anope/logs \
			${ANOPE_USER} ${ANOPE_GROUP} 2755
OWN_DIRS_PERMS+=	${PREFIX}/lib/anope/modules/runtime \
			${ANOPE_USER} ${ANOPE_GROUP} 2755

CONF_FILES_PERMS+=	${PREFIX}/share/examples/anope/example.conf \
			${PREFIX}/lib/anope/services.conf \
			${ANOPE_USER} ${ANOPE_GROUP} 0640

CONFIGURE_ARGS+=	--with-permissions=077
CONFIGURE_ARGS+=	--with-bindir=${PREFIX}/lib/anope
CONFIGURE_ARGS+=	--with-datadir=${PREFIX}/lib/anope
CONFIGURE_ARGS+=	--with-rungroup=${ANOPE_GROUP}

.include "options.mk"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	data/example.chk data/example.conf
SUBST_SED.paths=	-e "s|/home/ircd/services|${PREFIX}/lib/anope|g"
SUBST_SED.paths+=	-e "s|/usr/local/lib/services|${PREFIX}/lib/anope|g"
SUBST_SED.paths+=	-e "s|/home/username/services|${PREFIX}/lib/anope|g"
SUBST_MESSAGE.paths=	Fixing hardcoded paths.

SUBST_CLASSES+=		utils
SUBST_STAGE.utils=	pre-configure
SUBST_FILES.utils=	src/Makefile
SUBST_SED.utils=	-e "s|find|${FIND}|g"
SUBST_SED.utils+=	-e "s|chgrp|${CHGRP}|g"
SUBST_SED.utils+=	-e "s|chmod|${CHMOD}|g"
SUBST_SED.utils+=	-e "s|ln|${LN}|g"
SUBST_MESSAGE.utils=	Fixing hardcoded utilities.

.include "../../mk/pthread.buildlink3.mk"

# for backtrace
.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
LDFLAGS+=  -lexecinfo
.endif

INSTALLATION_DIRS+=	share/doc/anope share/examples/anope lib/anope/modules

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DESTDIR}${PREFIX}/share/doc/anope
	${CHMOD} ${BINMODE} ${DESTDIR}${PREFIX}/lib/anope/anoperc
	${CHMOD} ${BINMODE} ${DESTDIR}${PREFIX}/lib/anope/listchans
	${CHMOD} ${BINMODE} ${DESTDIR}${PREFIX}/lib/anope/listnicks
	${CHMOD} ${BINMODE} ${DESTDIR}${PREFIX}/lib/anope/services
	${CHMOD} ${BINMODE} ${DESTDIR}${PREFIX}/lib/anope/modules/*.so
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/lib/anope/languages/*
	${CHOWN} ${ANOPE_USER} ${DESTDIR}${PREFIX}/lib/anope
	${CHOWN} ${ANOPE_USER} ${DESTDIR}${PREFIX}/lib/anope/backups
	${CHOWN} ${ANOPE_USER} ${DESTDIR}${PREFIX}/lib/anope/logs
	${INSTALL_DATA} ${WRKSRC}/data/* ${DESTDIR}${PREFIX}/share/examples/anope

.include "../../mk/bsd.pkg.mk"
