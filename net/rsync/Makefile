# $NetBSD: Makefile,v 1.52.2.1 2004/05/10 08:54:30 agc Exp $

DISTNAME=	rsync-2.6.2
CATEGORIES=	net
MASTER_SITES=	http://rsync.samba.org/ftp/rsync/ \
		ftp://rsync.samba.org/pub/rsync/ \
		http://rsync.samba.org/ftp/rsync/old-versions/  \
		ftp://rsync.samba.org/pub/rsync/old-versions/  \
		ftp://sunsite.auc.dk/pub/unix/rsync/  \
		ftp://ftp.sunet.se/pub/unix/admin/rsync/  \
		ftp://ftp.fu-berlin.de/unix/network/rsync/

MAINTAINER=     tron@NetBSD.org
HOMEPAGE=	http://rsync.samba.org/
COMMENT=	Network file distribution/synchronisation utility

USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-included-popt

PKG_SYSCONFSUBDIR=	rsync

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	rsync.h rsync.1 rsyncd.conf.5
SUBST_SED.paths=	-e 's|/etc/rsyncd|${PKG_SYSCONFDIR}/rsyncd|g' \
			-e 's|/usr/bin/rsync|${PREFIX}/bin/rsync|g'

.include "../../mk/bsd.pkg.mk"
