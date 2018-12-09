# $NetBSD: Makefile,v 1.25 2018/12/09 21:05:32 adam Exp $

DISTNAME=	gputils-1.5.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gputils/}

MAINTAINER=	dogcow@NetBSD.org
HOMEPAGE=	http://gputils.sourceforge.net/
COMMENT=	Collection of tools for Microchip's PIC micro-processors
LICENSE=	gnu-gpl-v2

CONFLICTS=	gpasm-[0-9]*

GNU_CONFIGURE=	yes
USE_TOOLS+=	bison flex gmake

CONFIGURE_ARGS+=	--disable-html-doc

INSTALLATION_DIRS=	share/doc/gputils

post-install:
	for i in ps pdf lyx; do                         \
	  ${INSTALL_DATA} ${WRKSRC}/doc/gputils.$$i     \
	      ${DESTDIR}${PREFIX}/share/doc/gputils;    \
	done

.include "../../mk/bsd.pkg.mk"
