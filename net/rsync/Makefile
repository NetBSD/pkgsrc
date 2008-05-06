# $NetBSD: Makefile,v 1.71.2.1 2008/05/06 19:54:41 spz Exp $

DISTNAME=	rsync-2.6.9
CATEGORIES=	net
PKGREVISION=	2
MASTER_SITES=	http://rsync.samba.org/ftp/rsync/ \
		http://rsync.samba.org/ftp/rsync/old-versions/  \
		ftp://ftp.sunet.se/pub/unix/admin/rsync/  \
		ftp://ftp.fu-berlin.de/unix/network/rsync/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://rsync.samba.org/
COMMENT=	Network file distribution/synchronisation utility

PATCH_SITES=		http://rsync.samba.org/ftp/rsync/
PATCHFILES=		munge-symlinks-2.6.9.diff
PATCH_DIST_STRIP=	-p1

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
SUBST_FILES.paths=	rsync.h rsync.1 rsyncd.conf.5
SUBST_SED.paths=	-e 's|/etc/rsyncd|${PKG_SYSCONFDIR}/rsyncd|g' \
			-e 's|/usr/bin/rsync|${PREFIX}/bin/rsync|g'

.include "../../mk/bsd.pkg.mk"
