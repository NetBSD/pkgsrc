# $NetBSD: Makefile,v 1.26 2006/09/06 20:33:24 wiz Exp $
#

DISTNAME=		sfs-0.7.2
PKGREVISION=		6
CATEGORIES=		net security
MASTER_SITES=		http://www.fs.net/sfswww/dist/

MAINTAINER=		mike@ethmoid.org
HOMEPAGE=		http://www.fs.net/
COMMENT=		Secure, global, self-certifying network file system

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-sfsuser=sfs
CONFIGURE_ARGS+=	--with-sfsgroup=sfs
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-sfsdir=${SFS_ROOT:Q}
CONFIGURE_ARGS+=	--disable-uvfs

USE_LANGUAGES=		c c++
USE_TOOLS+=		makeinfo perl:run

GCC_REQD+=		2.95.3

INFO_FILES=		# PLIST

PKG_SYSCONFSUBDIR=	sfs
PKG_GROUPS=		sfs
PKG_USERS=		sfs:sfs
PKG_GECOS.sfs=		Self-certifying file system pseudo-user

RCD_SCRIPTS=		sfscd sfssd

.include "../../mk/bsd.prefs.mk"

SFSDIR?=		${VARBASE}/sfs
SFS_ROOT=		${SFSDIR}

OWN_DIRS_PERMS=		${SFS_ROOT} sfs sfs 555

SFSEXAMPLEDIR=		${PREFIX}/share/examples/sfs

MESSAGE_SUBST+=		SFSDIR=${SFS_ROOT} SFSEXAMPLEDIR=${SFSEXAMPLEDIR}

post-install:
	${INSTALL_DATA_DIR} ${SFSEXAMPLEDIR}
	@${SED} -e 's|@SFSDIR@|${SFS_ROOT}|g' ${FILESDIR}/sfsrwsd_config.sample \
		> ${SFSEXAMPLEDIR}/sfsrwsd_config.sample

.include "../../devel/gmp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
