# $NetBSD: Makefile,v 1.1.1.1 2005/02/25 16:24:07 is Exp $
#

DISTNAME=		vs
PKGNAME=		sr-examples-2.3.2
CATEGORIES=		lang parallel
MASTER_SITES=		ftp://ftp.cs.arizona.edu/sr/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://www.cs.arizona.edu/sr/
COMMENT=		The SR language compiler and run time system

WRKSRC= ${WRKDIR}

ONLY_FOR_PLATFORM=     NetBSD-*-*

### Use the second line below for installing if you want to make print-PLIST!
DOMOD=
#DOMOD=-pm

do-extract:

do-configure:

do-patch:

do-build:

do-install:
			${INSTALL_DATA_DIR} ${PREFIX}/share/examples/sr
			${PAX} -zr ${DOMOD} -f ${DISTDIR}/${DISTFILES} \
			  -s ,vsuite/examples,${PREFIX}/share/examples/sr, \
			  vsuite/examples

.include "../../mk/bsd.pkg.mk"
