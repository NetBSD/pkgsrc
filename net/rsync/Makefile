# $NetBSD: Makefile,v 1.7 1998/06/22 12:58:34 agc Exp $
# FreeBSD Id: Makefile,v 1.10 1998/01/03 10:14:21 obrien Exp
#

DISTNAME=	rsync-1.6.9
CATEGORIES=	net
MASTER_SITES=	ftp://samba.anu.edu.au/pub/rsync/  \
		ftp://sunsite.auc.dk/pub/unix/rsync/  \
		ftp://ftp.sunet.se/pub/unix/admin/rsync/  \
		ftp://ftp.fu-berlin.de/pub/unix/network/rsync/

MAINTAINER=     packages@netbsd.org

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

post-install:
	@strip ${PREFIX}/bin/rsync
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${WRKSRC}/tech_report.tex ${PREFIX}/share/doc/rsync
.endif

.include "../../mk/bsd.pkg.mk"
