# $NetBSD: Makefile,v 1.2 2002/07/02 12:41:25 wiz Exp $
#

DISTNAME=	epic4pre2-help
PKGNAME=	epic4-doc-1.0
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.epicsol.org/pub/epic/EPIC4-BETA/	\
		ftp://ftp.icm.edu.pl/pub/unix/irc/EPIC/EPIC4-BETA/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.epicsol.org/
COMMENT=	Additional documentation for epic4 package

DEPENDS+=	epic4>=1.0.1:../../chat/epic4

NO_BUILD=	YES

do-install:
	${CP} -R ${WRKDIR}/help/* ${PREFIX}/share/epic/help

.include "../../mk/bsd.pkg.mk"
