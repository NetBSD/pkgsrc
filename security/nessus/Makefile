# $NetBSD: Makefile,v 1.5 1999/03/23 16:19:49 bouyer Exp $
#

DISTNAME=	nessus-990318
CATEGORIES=	net security x11
MASTER_SITES=	ftp://ftp.nessus.org/pub/nessus/nessus-stable/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.nessus.org/

DEPENDS+=	gtk+-1.2.0:../../x11/gtk

GNU_CONFIGURE=	YES

post-install:
	${TOUCH} ${PREFIX}/share/nessus/reports/.keepme
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc
	${MV} ${PREFIX}/share/nessus/Manual ${PREFIX}/share/doc/nessus.txt

.include "../../mk/bsd.pkg.mk"
