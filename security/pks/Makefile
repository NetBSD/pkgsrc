# $NetBSD: Makefile,v 1.22 2005/12/05 23:55:18 rillig Exp $

DISTNAME=	pks-0.9.4
PKGREVISION=	3
CATEGORIES=	security www
MASTER_SITES+=	http://www.mit.edu/people/marc/pks/ \
		ftp://ftp.neonramp.com/pub/pksd/

PATCH_SITES=	http://www.mit.edu/people/marc/pks/ \
		ftp://ftp.neonramp.com/pub/pksd/
PATCHFILES=	pks094-patch2 \
		pks094-patch3
PATCH_DIST_STRIP=	-p1

MAINTAINER=	burgess@neonramp.com
HOMEPAGE=	http://www.mit.edu/people/marc/pks/
COMMENT=	PGP Public Key Server

USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES

PKS_USER=	pks
PKS_GROUP=	pks
PKS_SERVER?=	localhost
PKS_HOME=	${VARBASE}/pks

PKG_USERS=	${PKS_USER}:${PKS_GROUP}::PGP\ Key\ Server:${PKS_HOME}:${NOLOGIN}
PKG_GROUPS=	${PKS_GROUP}

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
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	pks-commands.html
SUBST_SED.paths=	-e "s|localhost|${PKS_SERVER}|g"

.include "../../databases/db/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/pks-commands.html ${PKS_HOME}/db/index.html
	@${CHOWN} ${PKS_USER} ${PKS_HOME}/db/index.html
	@${CHGRP} ${PKS_GROUP} ${PKS_HOME}/db/index.html

.include "../../mk/bsd.pkg.mk"
