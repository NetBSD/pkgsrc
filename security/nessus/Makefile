# $NetBSD: Makefile,v 1.2 1999/02/10 15:18:51 frueauf Exp $
#

DISTNAME=	nessus-990201
CATEGORIES=	net security x11
MASTER_SITES=	http://www.nessus.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.nessus.org/

DEPENDS+=	gtk+-1.1.12:../../x11/gtk

GNU_CONFIGURE=	YES

post-install:
	${TOUCH} ${PREFIX}/share/nessus/reports/.keepme
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc
	${MV} ${PREFIX}/share/nessus/Manual ${PREFIX}/share/doc/nessus.txt

.include "../../mk/bsd.pkg.mk"
