# $NetBSD: Makefile,v 1.1.1.1 2006/10/20 22:40:24 adrianp Exp $

DISTNAME=	anope-1.7.17
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=anope/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.anope.org/
COMMENT=	Set of Services for IRC networks

GNU_CONFIGURE=	YES
PTHREAD_OPTS+=	require
USE_TOOLS+=	gmake perl:run
ANOPE_USER=	anope
ANOPE_GROUP=	anope
RCD_SCRIPTS=	anope
FILES_SUBST+=	ANOPE_USER=${ANOPE_USER:Q}
FILES_SUBST+=	ANOPE_GROUP=${ANOPE_GROUP:Q}

.include "../../mk/bsd.prefs.mk"

PKG_USERS=	${ANOPE_USER}:${ANOPE_GROUP}::anope\ user:${PREFIX}/lib/anope:${NOLOGIN}
PKG_GROUPS=	${ANOPE_GROUP}
MAKE_ENV+=	RUNGROUP=${ANOPE_GROUP:Q}

CONF_FILES_PERMS+=	${PREFIX}/share/examples/anope/example.conf \
			${PREFIX}/lib/anope/services.conf \
			${ANOPE_USER} ${ANOPE_GROUP} 0640

CONFIGURE_ARGS+=	--with-permissions=077
CONFIGURE_ARGS+=	--with-bindir=${PREFIX}/lib/anope
CONFIGURE_ARGS+=	--with-datadir=${PREFIX}/lib/anope
CONFIGURE_ARGS+=	--with-rungroup=${ANOPE_GROUP:Q}

.include "options.mk"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	data/example.chk data/example.conf
SUBST_SED.paths=	-e "s|/home/ircd/services|${PREFIX}/lib/anope|g"
SUBST_SED.paths+=	-e "s|/usr/local/lib/services|${PREFIX}/lib/anope|g"
SUBST_SED.paths+=	-e "s|/home/username/services|${PREFIX}/lib/anope|g"
SUBST_MESSAGE.paths=	Fixing hardcoded paths.

SUBST_CLASSES+=		utils
SUBST_STAGE.utils=	post-patch
SUBST_FILES.utils=	src/Makefile
SUBST_SED.utils=	-e "s|find|${FIND}|g"
SUBST_SED.utils+=	-e "s|chgrp|${CHGRP}|g"
SUBST_SED.utils+=	-e "s|chmod|${CHMOD}|g"
SUBST_SED.utils+=	-e "s|ln|${LN}|g"
SUBST_MESSAGE.utils=	Fixing hardcoded utilities.

.include "../../mk/pthread.buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/anope
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/anope
	${INSTALL_DATA} ${WRKSRC}/docs/* ${PREFIX}/share/doc/anope
	${CHMOD} ${BINMODE} ${PREFIX}/lib/anope/anoperc
	${CHMOD} ${BINMODE} ${PREFIX}/lib/anope/listchans
	${CHMOD} ${BINMODE} ${PREFIX}/lib/anope/listnicks
	${CHMOD} ${BINMODE} ${PREFIX}/lib/anope/services
	${CHMOD} ${BINMODE} ${PREFIX}/lib/anope/modules/*.so
	${CHOWN} ${ANOPE_USER} ${PREFIX}/lib/anope
	${CHOWN} ${ANOPE_USER} ${PREFIX}/lib/anope/backups
	${CHOWN} ${ANOPE_USER} ${PREFIX}/lib/anope/logs
	${INSTALL_DATA} ${WRKSRC}/data/* ${PREFIX}/share/examples/anope

.include "../../mk/bsd.pkg.mk"
