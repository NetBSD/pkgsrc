# $NetBSD: Makefile,v 1.1.1.1 2001/04/27 15:46:03 zuntum Exp $
#

DISTNAME=	qmHandle-0.4.1
CATEGORIES=	mail
MASTER_SITES=	http://www.io.com/~mick/soft/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.io.com/~mick/soft/qmhandle.html
COMMENT=	tool to view and manage the qmail message queue

WRKSRC=		${WRKDIR}

USE_PERL5=	YES
NO_BUILD=	YES

post-patch:
	${SED} "s,/usr/bin/perl,${LOCALBASE}/bin/perl,g"	\
		${WRKSRC}/qmHandle > ${WRKSRC}/qmHandle.done
	${MV} ${WRKSRC}/qmHandle.done ${WRKSRC}/qmHandle

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qmHandle ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/qmHandle.README

.include "../../mk/bsd.pkg.mk"
