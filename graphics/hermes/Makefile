# $NetBSD: Makefile,v 1.11 2003/01/19 06:59:52 salo Exp $

DISTNAME=		Hermes-1.3.2
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://dark.x.dtu.dk/~mbn/clanlib/download/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanlib.org/hermes/
COMMENT=		Library for conversion of pixel graphics

WRKSRC=			${WRKDIR}/Hermes-1.3.2

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

.include "../../mk/bsd.pkg.mk"
