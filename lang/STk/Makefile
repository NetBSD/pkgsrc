# $NetBSD: Makefile,v 1.3 1998/07/21 14:58:43 agc Exp $
#

DISTNAME=       STk-3.99.2
CATEGORIES=	lang
MASTER_SITES=	ftp://kaolin.unice.fr/pub/STk/

MAINTAINER=	perry@NetBSD.ORG

GNU_CONFIGURE=	yes

PLIST_SRC=	${WRKDIR}/PLIST.tmp

.include "../../mk/bsd.prefs.mk"

.ifndef OPSYS
OPSYS!=		uname -s
.endif

OS_VERSION!=	uname -r

pre-install:
	@${SED} -e 's|\$${OS_VERSION}|${OS_VERSION}|g'	\
		-e 's|\$${OPSYS}|${OPSYS}|g'		\
		${PKGDIR}/PLIST > ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
