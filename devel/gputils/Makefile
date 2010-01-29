# $NetBSD: Makefile,v 1.11 2010/01/29 18:02:12 joerg Exp $

DISTNAME=	gputils-0.13.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gputils/}

MAINTAINER=	dogcow@NetBSD.org
HOMEPAGE=	http://gputils.sourceforge.net/
COMMENT=	collection of tools for Microchip's PIC micro-processors

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	gpasm-*

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

INSTALLATION_DIRS==	share/doc/gputils

post-install:
	for i in ps pdf lyx; do                         \
	  ${INSTALL_DATA} ${WRKSRC}/doc/gputils.$$i     \
	      ${DESTDIR}${PREFIX}/share/doc/gputils;    \
	done

.include "../../mk/bsd.pkg.mk"
