# $NetBSD: Makefile,v 1.8 2003/07/17 21:46:53 grant Exp $
#

DISTNAME=	qmHandle-1.0.0
WRKSRC=		${WRKDIR}
CATEGORIES=	mail
MASTER_SITES=	http://www.italpro.net/mb/soft/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.italpro.net/mb/soft/qmhandle.html
COMMENT=	tool to view and manage the qmail message queue

RESTRICTED=	"Contact author before reselling"

USE_PERL5=	YES
REPLACE_PERL=	qmHandle
NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qmHandle ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/qmHandle.README

.include "../../mk/bsd.pkg.mk"
