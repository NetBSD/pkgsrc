# $NetBSD: Makefile,v 1.1.1.1 1999/02/08 17:17:48 hubertf Exp $
#

DISTNAME=	nessus-990201
EXTRACT_SUFX=	.tgz
CATEGORIES=	net security x11
MASTER_SITES=	http://www.nessus.org/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.nessus.org/

DEPENDS+=	gtk+-1.1.12:../../x11/gtk

GNU_CONFIGURE=	YES

post-install:
	${TOUCH} ${PREFIX}/share/nessus/reports/.keepme
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc
	${MV} ${PREFIX}/share/nessus/Manual ${PREFIX}/share/doc/nessus.txt

.include "../../mk/bsd.pkg.mk"
