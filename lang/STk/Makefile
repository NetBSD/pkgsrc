# $NetBSD: Makefile,v 1.5 1998/08/20 15:17:03 tsarna Exp $
#

DISTNAME=       STk-3.99.2
CATEGORIES=	lang
MASTER_SITES=	ftp://kaolin.unice.fr/pub/STk/

MAINTAINER=	perry@netbsd.org
HOMEPAGE=	http://kaolin.unice.fr/STk/

GNU_CONFIGURE=	yes

PLIST_SRC=	${WRKDIR}/PLIST.tmp

.include "../../mk/bsd.prefs.mk"

OS_VERSION!=	/usr/bin/uname -r

pre-install:
	@${SED} -e 's|\$${OS_VERSION}|${OS_VERSION}|g' ${PKGDIR}/PLIST > ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
