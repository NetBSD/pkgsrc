# $NetBSD: Makefile,v 1.20 1999/05/12 23:31:04 tv Exp $
#

DISTNAME=	rsync-2.3.1
CATEGORIES=	net
MASTER_SITES=	ftp://rsync.samba.org/pub/rsync/ \
		ftp://sunsite.auc.dk/pub/unix/rsync/  \
		ftp://ftp0.sunet.se/pub/unix/admin/rsync/  \
		ftp://ftp.fu-berlin.de/pub/unix/network/rsync/

MAINTAINER=     mycroft@netbsd.org
HOMEPAGE=	http://samba.anu.edu.au/rsync/

GNU_CONFIGURE=	yes

post-install:
	@strip ${PREFIX}/bin/rsync
	@${MKDIR} ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${WRKSRC}/tech_report.tex ${PREFIX}/share/doc/rsync

.include "../../mk/bsd.pkg.mk"
