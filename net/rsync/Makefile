# 	$NetBSD: Makefile,v 1.1.1.1 1998/01/23 09:57:21 agc Exp $
#
# New ports collection makefile for:    rsync
# Version required:     1.6.9
# Date created:         Sat Aug 3, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# FreeBSD Id: Makefile,v 1.10 1998/01/03 10:14:21 obrien Exp
#

DISTNAME=	rsync-1.6.9
CATEGORIES=	net
MASTER_SITES=	ftp://samba.anu.edu.au/pub/rsync/  \
		ftp://sunsite.auc.dk/pub/unix/rsync/  \
		ftp://ftp.sunet.se/pub/unix/admin/rsync  \
		ftp://ftp.fu-berlin.de/pub/unix/network/rsync/

MAINTAINER=     obrien@FreeBSD.org

GNU_CONFIGURE=	yes
MAN1=		rsync.1

post-install:
	@strip ${PREFIX}/bin/rsync
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${WRKSRC}/tech_report.tex ${PREFIX}/share/doc/rsync
.endif

.include <bsd.port.mk>
