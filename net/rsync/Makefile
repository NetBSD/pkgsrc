# $NetBSD: Makefile,v 1.49 2003/12/04 10:57:42 tron Exp $

DISTNAME=	rsync-2.5.7
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

post-patch:
	@cd ${WRKSRC} && \
	for f in rsync.h rsync.1 rsyncd.conf.5 ; do \
		${MV} $${f} $${f}.orig;			\
		${SED} ${FILES_SUBST_SED} $${f}.orig > $${f};	\
	done

.include "../../mk/bsd.pkg.mk"
