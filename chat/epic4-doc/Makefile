# $NetBSD: Makefile,v 1.6 2005/06/16 06:57:42 jlam Exp $
#

DISTNAME=	epic4-help-20050315
PKGNAME=	epic4-doc-1.0.20050315
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.epicsol.org/pub/epic/EPIC4-PRODUCTION/ \
		ftp://ftp.freenet.de/pub/ftp.prbh.org/pub/epic/EPIC4-PRODUCTION/ \
		http://ftp.freenet.de/pub/ftp.prbh.org/pub/epic/EPIC4-PRODUCTION/ \
		ftp://totem.fix.no/pub/mirrors/epic/EPIC4-PRODUCTION/ \
		ftp://ftp.eu.uu.net/pub/unix/irc/epic/EPIC4-PRODUCTION/ \
		ftp://ftp.irc.org/irc/clients/unix/epic/EPIC4-PRODUCTION/ \
		ftp://ftp.parodius.com/pub/epic/EPIC4-PRODUCTION/ \
		ftp://ftp.icm.edu.pl/pub/unix/irc/EPIC/EPIC4-PRODUCTION/ \
		ftp://ftp.archive.de.uu.net/pub/unix/irc/epic/EPIC4-PRODUCTION/ \
		ftp://ftp.nl.uu.net/pub/unix/irc/epic/EPIC4-PRODUCTION/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.epicsol.org/
COMMENT=	Additional documentation for epic4 package

DEPENDS+=	epic4>=2.0:../../chat/epic4

NO_BUILD=	YES

INSTALLATION_DIRS=	share/epic/help

do-install:
	${CP} -R ${WRKDIR}/help/* ${PREFIX}/share/epic/help
	${RM} -r ${PREFIX}/share/epic/help/Makefile
	${RM} -r ${PREFIX}/share/epic/help/CVS
	${RM} -r ${PREFIX}/share/epic/help/*/CVS
	${RM} -r ${PREFIX}/share/epic/help/*/*/CVS

.include "../../mk/bsd.pkg.mk"
