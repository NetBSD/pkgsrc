# $NetBSD: Makefile,v 1.28 2010/02/25 14:59:22 joerg Exp $

DISTNAME=	pks-0.9.4
PKGREVISION=	3
CATEGORIES=	security www
MASTER_SITES+=	http://www.mit.edu/people/marc/pks/ \
	${MASTER_SITE_SOURCEFORGE:=pks/} 
PATCH_SITES=	http://www.mit.edu/people/marc/pks/
PATCHFILES=	pks094-patch2 \
		pks094-patch3
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mit.edu/people/marc/pks/
COMMENT=	PGP Public Key Server

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

.include "../../databases/db/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/pks-commands.html ${PKS_HOME}/db/index.html
	@${CHOWN} ${PKS_USER} ${PKS_HOME}/db/index.html
	@${CHGRP} ${PKS_GROUP} ${PKS_HOME}/db/index.html

.include "../../mk/bsd.pkg.mk"
