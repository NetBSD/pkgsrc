# $NetBSD: Makefile,v 1.19 2004/02/14 00:54:45 grant Exp $

DISTNAME=		Hermes-1.3.3
CATEGORIES=		graphics
MASTER_SITES=		http://www.clanlib.org/download/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanlib.org/hermes/
COMMENT=		Library for conversion of pixel graphics

WRKSRC=			${WRKDIR}/Hermes-1.3.3
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../mk/bsd.pkg.mk"
