# $NetBSD: Makefile,v 1.45 2003/03/06 20:44:13 salo Exp $
#

DISTNAME=	rsync-2.5.6
CATEGORIES=	net
MASTER_SITES=	http://rsync.samba.org/ftp/rsync/ \
		ftp://rsync.samba.org/pub/rsync/ \
		http://rsync.samba.org/ftp/rsync/old-versions/  \
		ftp://rsync.samba.org/pub/rsync/old-versions/  \
		ftp://sunsite.auc.dk/pub/unix/rsync/  \
		ftp://ftp0.sunet.se/pub/unix/admin/rsync/  \
		ftp://ftp.fu-berlin.de/unix/network/rsync/

MAINTAINER=     tron@netbsd.org
HOMEPAGE=	http://rsync.samba.org/
COMMENT=	Network file distribution/synchronisation utility

USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-included-popt

PKG_SYSCONFSUBDIR=	rsync

post-patch:
	@cd ${WRKSRC} && \
	for f in rsync.h rsync.1 rsyncd.conf.5 ; do \
		${MV} $${f} $${f}.orig;			\
		${SED} ${FILES_SUBST_SED} $${f}.orig > $${f};	\
	done

.include "../../mk/bsd.pkg.mk"
