# $NetBSD: Makefile,v 1.34 2017/09/03 08:36:59 wiz Exp $

DISTNAME=	pks-0.9.4
PKGREVISION=	5
CATEGORIES=	security www
#MASTER_SITES+=	http://www.mit.edu/people/marc/pks/
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=pks/}
#PATCH_SITES=	http://www.mit.edu/people/marc/pks/
PATCHFILES=	pks094-patch2 \
		pks094-patch3
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.mit.edu/people/marc/pks/
COMMENT=	PGP Public Key Server
LICENSE=	original-bsd

GNU_CONFIGURE=	YES

PKG_GROUPS_VARS+=	PKS_GROUP
PKG_USERS_VARS+=	PKS_USER

PKS_USER=	pks
PKS_GROUP=	pks
PKS_SERVER?=	localhost
PKS_HOME=	${VARBASE}/pks

PKG_GROUPS=	${PKS_GROUP}
PKG_USERS=	${PKS_USER}:${PKS_GROUP}

PKG_GECOS.${PKS_USER}=	PGP Key Server
PKG_HOME.${PKS_USER}=	${PKS_HOME}

BDB_ACCEPTED=	db2

BUILD_DEFS+=	PKS_SERVER

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/pksd.conf ${PKG_SYSCONFDIR}/pksd.conf
RCD_SCRIPTS=	pksd

FILES_SUBST+=	PKS_USER=${PKS_USER:Q}
FILES_SUBST+=	PKS_GROUP=${PKS_GROUP:Q}

OWN_DIRS_PERMS+=	${PKS_HOME} ${PKS_USER} ${PKS_GROUP} 0770
OWN_DIRS_PERMS+=	${PKS_HOME}/db ${PKS_USER} ${PKS_GROUP} 0770
OWN_DIRS_PERMS+=	${PKS_HOME}/incoming ${PKS_USER} ${PKS_GROUP} 0770

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/pks
CONFIGURE_ARGS+=	--localstatedir=${PKS_HOME:Q}
#
# pksd doesn't actually look for its config file anywhere; it must be
# specified directly on the command-line.  Setting sysconfdir here just
# causes the example pksd.conf file to be installed at the named location.
#
CONFIGURE_ARGS+=	--sysconfdir=${EGDIR:Q}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	pks-commands.html
SUBST_SED.paths=	-e "s|localhost|${PKS_SERVER}|g"

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	datadir=${DESTDIR}${PREFIX}/share/pks
INSTALL_MAKE_FLAGS+=	localstatedir=${DESTDIR}${PKS_HOME}
INSTALL_MAKE_FLAGS+=	man5dir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
INSTALL_MAKE_FLAGS+=	man8dir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
INSTALL_MAKE_FLAGS+=	sysconfdir=${DESTDIR}${EGDIR:Q}

.include "../../databases/db/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/pks-commands.html ${DESTDIR}${EGDIR}

CONF_FILES_PERMS=	${EGDIR}/pks-commands.html ${PKS_HOME}/db/index.html \
			${PKS_USER} ${PKS_GROUP} ${SHAREMODE}

.include "../../mk/bsd.pkg.mk"
