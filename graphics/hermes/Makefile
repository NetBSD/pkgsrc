# $NetBSD: Makefile,v 1.15 2003/11/06 19:29:06 gavan Exp $

DISTNAME=		Hermes-1.3.3
WRKSRC=			${WRKDIR}/Hermes-1.3.3
CATEGORIES=		graphics
MASTER_SITES=		http://www.clanlib.org/download/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanlib.org/hermes/
COMMENT=		Library for conversion of pixel graphics

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub
USE_GMAKE=		yes

.include "../../mk/bsd.pkg.mk"
