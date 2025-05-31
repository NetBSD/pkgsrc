# $NetBSD: Makefile,v 1.15 2025/05/31 23:47:48 zafer Exp $

DISTNAME=	epic4-help-20050315
PKGNAME=	epic4-doc-1.0.20050315
CATEGORIES=	chat
MASTER_SITES=	https://ftp.epicsol.org/pub/epic/EPIC4-PRODUCTION/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.epicsol.org/
COMMENT=	Additional documentation for epic4 package

DEPENDS+=	epic4>=2.0:../../chat/epic4

NO_BUILD=	YES

INSTALLATION_DIRS=	share/epic/help

do-install:
	${CP} -R ${WRKDIR}/help/* ${DESTDIR}${PREFIX}/share/epic/help
	${RM} -r ${DESTDIR}${PREFIX}/share/epic/help/Makefile
	${RM} -r ${DESTDIR}${PREFIX}/share/epic/help/CVS
	${RM} -r ${DESTDIR}${PREFIX}/share/epic/help/*/CVS
	${RM} -r ${DESTDIR}${PREFIX}/share/epic/help/*/*/CVS

.include "../../mk/bsd.pkg.mk"
