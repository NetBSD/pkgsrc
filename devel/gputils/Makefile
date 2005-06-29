# $NetBSD: Makefile,v 1.5 2005/06/29 09:33:26 dogcow Exp $

DISTNAME=	gputils-0.13.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gputils/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=       http://gputils.sourceforge.net/
COMMENT=	collection of tools for Microchip's PIC micro-processors

CONFLICTS=	gpasm-*

GNU_CONFIGURE=  yes
USE_TOOLS+=	gmake

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gputils
		for i in ps pdf lyx; do                         \
		  ${INSTALL_DATA} ${WRKSRC}/doc/gputils.$$i     \
		      ${PREFIX}/share/doc/gputils;              \
		done

.include "../../mk/bsd.pkg.mk"
