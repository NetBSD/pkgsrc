# $NetBSD: Makefile,v 1.38 2002/01/26 19:04:49 bouyer Exp $

DISTNAME=	rsync-2.5.2
CATEGORIES=	net
MASTER_SITES=	ftp://rsync.samba.org/pub/rsync/ \
		ftp://sunsite.auc.dk/pub/unix/rsync/  \
		ftp://ftp0.sunet.se/pub/unix/admin/rsync/  \
		ftp://ftp.fu-berlin.de/unix/network/rsync/

MAINTAINER=     tron@netbsd.org
HOMEPAGE=	http://rsync.samba.org/
COMMENT=	Network file distribution/synchronisation utility

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-included-popt

post-install:
	@strip ${PREFIX}/bin/rsync
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${WRKSRC}/tech_report.tex ${PREFIX}/share/doc/rsync

.include "../../mk/bsd.pkg.mk"
