# $NetBSD: Makefile,v 1.2 2003/02/01 15:16:24 dmcmahill Exp $
#

DISTNAME=	atlc-4.2.10
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=atlc/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://atlc.sourceforge.net
COMMENT=	Calculates the impedance of arbitrary cross section transmission lines

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
# note:  the check target builds some of the
# example files which get installed.
ALL_TARGET=	all check
TEST_DIRS=	${WRKSRC}
TEST_TARGET=	check

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/atlc
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/atlc

.include "../../math/gsl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
