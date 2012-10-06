# $NetBSD: Makefile,v 1.7 2012/10/06 11:54:30 asau Exp $
#

DISTNAME=	an-0.93
CATEGORIES=	games
MASTER_SITES=	ftp://suburbia.net/pub/rmj/

MAINTAINER=	jonb@NetBSD.org
COMMENT=	Very fast anagram generator

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

INSTALL_MAKE_FLAGS=	INSTALLDIR=${DESTDIR}${PREFIX}/bin \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man6

WRKSRC=		${WRKDIR}/an-0.93

.include "../../mk/bsd.pkg.mk"
