# $NetBSD: Makefile,v 1.35 2010/03/24 19:43:28 asau Exp $
#

DISTNAME=		sfs-0.7.2
PKGREVISION=		11
CATEGORIES=		net security
MASTER_SITES=		${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.fs.net/sfswww/
COMMENT=		Secure, global, self-certifying network file system

GNU_CONFIGURE=		yes

SFS_USER?=		sfs
SFS_GROUP?=		sfs

CONFIGURE_ARGS+=	--with-sfsuser=${SFS_USER}
CONFIGURE_ARGS+=	--with-sfsgroup=${SFS_GROUP}
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-sfsdir=${SFS_ROOT:Q}
CONFIGURE_ARGS+=	--disable-uvfs

USE_LANGUAGES=		c c++
USE_TOOLS+=		makeinfo perl:run lex

INFO_FILES=		# PLIST

PKG_SYSCONFSUBDIR=	sfs
PKG_GROUPS=		${SFS_GROUP}
PKG_USERS=		${SFS_USER}:${SFS_GROUP}
PKG_GECOS.${SFS_USER}=	Self-certifying file system pseudo-user

RCD_SCRIPTS=		sfscd sfssd

.include "../../mk/bsd.prefs.mk"

SFSDIR?=		${VARBASE}/sfs
SFS_ROOT=		${SFSDIR}

OWN_DIRS_PERMS=		${SFS_ROOT} ${SFS_USER} ${SFS_GROUP} 555

SFSEXAMPLEDIR=		${PREFIX}/share/examples/sfs

MESSAGE_SUBST+=		SFSDIR=${SFS_ROOT} SFSEXAMPLEDIR=${SFSEXAMPLEDIR}

post-install:
	${INSTALL_DATA_DIR} ${SFSEXAMPLEDIR}
	@${SED} -e 's|@SFSDIR@|${SFS_ROOT}|g' ${FILESDIR}/sfsrwsd_config.sample \
		> ${SFSEXAMPLEDIR}/sfsrwsd_config.sample

.include "../../devel/gmp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
