# $NetBSD: Makefile,v 1.1.1.1 2003/08/03 23:54:29 wulf Exp $

DISTNAME=	gputils-0.11.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gputils/}

MAINTAINER=	wulf@netbsd.org
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
