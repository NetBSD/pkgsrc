# $NetBSD: Makefile,v 1.3 2003/07/17 21:25:39 grant Exp $
#

DISTNAME=	epic4pre2-help
PKGNAME=	epic4-doc-1.0
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.epicsol.org/pub/epic/EPIC4-BETA/	\
		ftp://ftp.icm.edu.pl/pub/unix/irc/EPIC/EPIC4-BETA/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.epicsol.org/
COMMENT=	Additional documentation for epic4 package

DEPENDS+=	epic4>=1.0.1:../../chat/epic4

NO_BUILD=	YES

do-install:
	${CP} -R ${WRKDIR}/help/* ${PREFIX}/share/epic/help

.include "../../mk/bsd.pkg.mk"
