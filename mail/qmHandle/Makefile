# $NetBSD: Makefile,v 1.3 2001/06/04 22:26:32 jtb Exp $
#

DISTNAME=	qmHandle-0.5.0
CATEGORIES=	mail
MASTER_SITES=	http://www.io.com/~mick/soft/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.io.com/~mick/soft/qmhandle.html
COMMENT=	tool to view and manage the qmail message queue

RESTRICTED=	"Contact author before reselling"

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
