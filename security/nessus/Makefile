# $NetBSD: Makefile,v 1.3 1999/03/04 09:30:45 tron Exp $
#

DISTNAME=	nessus-990201
CATEGORIES=	net security x11
MASTER_SITES=	http://www.nessus.org/
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
