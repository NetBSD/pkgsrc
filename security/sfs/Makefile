# $NetBSD: Makefile,v 1.1.1.1 2003/03/17 21:01:47 agc Exp $
#

DISTNAME=		sfs-0.7.2
CATEGORIES=		net security
MASTER_SITES=		http://www.fs.net/sfs/@new-york.lcs.mit.edu,u83s4uk49nt8rmp4uwmt2exvz6d3cavh/pub/sfswww/dist/

MAINTAINER=		mike@ethmoid.org
HOMEPAGE=		http://www.fs.net/
COMMENT=		Secure, global, self-certifying network file system

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-sfsuser=sfs
CONFIGURE_ARGS+=	--with-sfsgroup=sfs
CONFIGURE_ARGS+=	--with-etcdir=${PREFIX}/etc/sfs
CONFIGURE_ARGS+=	--disable-uvfs

USE_PKGINSTALL=		yes
USE_BUILDLINK2=		yes
USE_PERL5=		yes

DIST_GCC=		2.95.3

PKG_USERS=              sfs:sfs::Self-certifying\\ file\\ system:/
PKG_GROUPS=             sfs

.include "../../mk/bsd.prefs.mk"

SFSDIR?=		${PREFIX}/var/sfs
SFS_ROOT=		${SFSDIR}

CONFIGURE_ARGS+=	--with-sfsdir=${SFS_ROOT}

MESSAGE_SUBST+=         SFSDIR=${SFS_ROOT}

INFO_FILES=		sfs.info

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/sfs
	${INSTALL_DATA_DIR} ${SFS_ROOT}

post-install:
	@${SED} -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/sfscd \
		> ${PREFIX}/etc/rc.d/sfscd
	@${CHMOD} +x ${PREFIX}/etc/rc.d/sfscd
	@${SED} -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/sfssd \
		> ${PREFIX}/etc/rc.d/sfssd
	@${CHMOD} +x ${PREFIX}/etc/rc.d/sfssd
	@${SED} -e 's|@SFSDIR@|${SFS_ROOT}|g' ${FILESDIR}/sfsrwsd_config.sample \
		> ${PREFIX}/etc/sfs/sfsrwsd_config.sample

.include "../../devel/gmp/buildlink2.mk"
.include "../../lang/gcc/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
