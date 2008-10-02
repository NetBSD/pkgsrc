# $NetBSD: Makefile,v 1.78 2008/10/02 08:17:15 tron Exp $

DISTNAME=	rsync-3.0.4
CATEGORIES=	net
MASTER_SITES=	http://rsync.samba.org/ftp/rsync/ \
		http://rsync.samba.org/ftp/rsync/old-versions/  \
		ftp://ftp.sunet.se/pub/unix/admin/rsync/  \
		ftp://ftp.fu-berlin.de/unix/network/rsync/

OWNER=		tron@NetBSD.org
HOMEPAGE=	http://rsync.samba.org/
COMMENT=	Network file distribution/synchronisation utility

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 share/doc/rsync

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-included-popt \
			--with-rsyncd-conf=${PKG_SYSCONFDIR}/rsyncd.conf
TEST_TARGET=		test

PKG_SYSCONFSUBDIR=	rsync

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	rsync.1 rsyncd.conf.5
SUBST_SED.paths=	-e 's|/etc/rsyncd|${PKG_SYSCONFDIR}/rsyncd|g'
SUBST_SED.paths+=	-e 's|/usr/bin/rsync|${PREFIX}/bin/rsync|g'

.include "../../mk/bsd.pkg.mk"
