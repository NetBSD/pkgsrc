# $NetBSD: Makefile,v 1.1.1.1 2002/03/13 12:42:59 dmcmahill Exp $
#

DISTNAME=	atlc-2.32
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=atlc/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://atlc.sourceforge.net
COMMENT=	Calculates the impedance of arbitrary cross section transmission lines

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/atlc
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/atlc

.include "../../mk/bsd.pkg.mk"
