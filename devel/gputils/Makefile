# $NetBSD: Makefile,v 1.2 2003/12/24 09:53:48 jmmv Exp $

DISTNAME=	gputils-0.11.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gputils/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=       http://gputils.sourceforge.net/
COMMENT=	collection of tools for Microchip's PIC micro-processors

CONFLICTS=	gpasm-*

GNU_CONFIGURE=  yes
USE_GMAKE=      yes

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gputils
		for i in ps pdf lyx; do                         \
		  ${INSTALL_DATA} ${WRKSRC}/doc/gputils.$$i     \
		      ${PREFIX}/share/doc/gputils;              \
		done

.include "../../mk/bsd.pkg.mk"
