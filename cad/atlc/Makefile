# $NetBSD: Makefile,v 1.11 2005/06/15 02:21:03 dmcmahill Exp $
#

DISTNAME=	atlc-4.6.0
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=atlc/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://atlc.sourceforge.net/
COMMENT=	Calculates the impedance of arbitrary cross section transmission lines

GNU_CONFIGURE=	YES
# note:  the check target builds some of the
# example files which get installed.
BUILD_TARGET=	all check
TEST_DIRS=	${WRKSRC}
TEST_TARGET=	check

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/atlc
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/atlc
	${RM} -f ${PREFIX}/share/examples/atlc/Makefile

.include "../../mk/bsd.pkg.mk"
