# $NetBSD: Makefile,v 1.9 1999/08/28 09:43:14 rh Exp $
#

DISTNAME=	nessus-990318
CATEGORIES=	net security x11
MASTER_SITES=	ftp://ftp.nessus.org/pub/nessus/nessus-stable/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.nessus.org/

DEPENDS+=	gtk+-1.2.4:../../x11/gtk

USE_X11=	yes
GNU_CONFIGURE=	YES

post-install:
	${TOUCH} ${PREFIX}/share/nessus/reports/.keepme
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc
	${MV} ${PREFIX}/share/nessus/Manual ${PREFIX}/share/doc/nessus.txt

.include "../../mk/bsd.pkg.mk"
