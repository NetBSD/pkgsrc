# $NetBSD: Makefile,v 1.6 2004/10/03 00:13:12 tv Exp $
#

DISTNAME=	atlc-4.2.10
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=atlc/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://atlc.sourceforge.net/
COMMENT=	Calculates the impedance of arbitrary cross section transmission lines

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
# note:  the check target builds some of the
# example files which get installed.
ALL_TARGET=	all check
TEST_DIRS=	${WRKSRC}
TEST_TARGET=	check

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/atlc
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/atlc

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
