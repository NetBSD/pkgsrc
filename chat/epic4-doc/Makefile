# $NetBSD: Makefile,v 1.14 2019/02/04 09:34:48 wiz Exp $

DISTNAME=	epic4-help-20050315
PKGNAME=	epic4-doc-1.0.20050315
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.epicsol.org/pub/epic/EPIC4-PRODUCTION/
MASTER_SITES+=	ftp://totem.fix.no/pub/mirrors/epic/EPIC4-PRODUCTION/

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
