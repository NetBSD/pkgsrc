# $NetBSD: Makefile,v 1.14 2003/10/28 23:09:51 kristerw Exp $

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
GNU_CONFIGURE=		yes
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub
USE_GMAKE=		yes

.include "../../mk/bsd.pkg.mk"
