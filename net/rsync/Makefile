# $NetBSD: Makefile,v 1.17 1999/04/08 10:27:30 hubertf Exp $
#

DISTNAME=	rsync-2.3.1
CATEGORIES=	net
MASTER_SITES=	ftp://rsync.samba.org/pub/rsync/old-versions/ \
		ftp://sunsite.auc.dk/pub/unix/rsync/  \
		ftp://ftp.sunet.se/pub/unix/admin/rsync/  \
		ftp://ftp.fu-berlin.de/pub/unix/network/rsync/

MAINTAINER=     mycroft@netbsd.org
HOMEPAGE=	http://samba.anu.edu.au/rsync/

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

post-install:
	@strip ${PREFIX}/bin/rsync
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${WRKSRC}/tech_report.tex ${PREFIX}/share/doc/rsync
.endif

.include "../../mk/bsd.pkg.mk"
