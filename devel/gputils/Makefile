# $NetBSD: Makefile,v 1.23 2016/09/18 05:28:02 dholland Exp $

DISTNAME=	gputils-1.4.2-1
PKGNAME=	gputils-1.4.2.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gputils/}

MAINTAINER=	dogcow@NetBSD.org
HOMEPAGE=	http://gputils.sourceforge.net/
COMMENT=	Collection of tools for Microchip's PIC micro-processors

CONFLICTS=	gpasm-[0-9]*
WRKSRC=		${WRKDIR}/gputils-1.4.2

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
