# $NetBSD: Makefile,v 1.16 2004/10/03 00:18:13 tv Exp $
#

DISTNAME=		sfs-0.7.2
PKGREVISION=		4
CATEGORIES=		net security
MASTER_SITES=		http://www.fs.net/sfs/@new-york.lcs.mit.edu,u83s4uk49nt8rmp4uwmt2exvz6d3cavh/pub/sfswww/dist/

MAINTAINER=		mike@ethmoid.org
HOMEPAGE=		http://www.fs.net/
COMMENT=		Secure, global, self-certifying network file system

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-sfsuser=sfs
CONFIGURE_ARGS+=	--with-sfsgroup=sfs
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-sfsdir=${SFS_ROOT}
CONFIGURE_ARGS+=	--disable-uvfs

USE_PKGINSTALL=		yes
USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
USE_PERL5=		yes

GCC_REQD+=		2.95.3

PKG_USERS=		sfs:sfs::Self-certifying\\ file\\ system:/
PKG_GROUPS=		sfs
PKG_SYSCONFSUBDIR=	sfs

RCD_SCRIPTS=		sfscd sfssd

.include "../../mk/bsd.prefs.mk"

SFSDIR?=		/var/sfs
SFS_ROOT=		${SFSDIR}

OWN_DIRS_PERMS=		${SFS_ROOT} sfs sfs 555

SFSEXAMPLEDIR=		${PREFIX}/share/examples/sfs

MESSAGE_SUBST+=		SFSDIR=${SFS_ROOT} SFSEXAMPLEDIR=${SFSEXAMPLEDIR}

USE_MAKEINFO=		YES
INFO_FILES=		sfs.info

post-install:
	${INSTALL_DATA_DIR} ${SFSEXAMPLEDIR}
	@${SED} -e 's|@SFSDIR@|${SFS_ROOT}|g' ${FILESDIR}/sfsrwsd_config.sample \
		> ${SFSEXAMPLEDIR}/sfsrwsd_config.sample

.include "../../devel/gmp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
