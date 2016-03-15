# $NetBSD: Makefile,v 1.21 2016/03/15 20:39:52 bouyer Exp $

DISTNAME=	gputils-1.4.2-1
PKGNAME=	gputils-1.4.2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gputils/}
WRKSRC=		${WRKDIR}/gputils-1.4.2

MAINTAINER=	dogcow@NetBSD.org
HOMEPAGE=	http://gputils.sourceforge.net/
COMMENT=	Collection of tools for Microchip's PIC micro-processors

CONFLICTS=	gpasm-*

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
