# $NetBSD: Makefile,v 1.12 2003/03/29 12:41:16 jmmv Exp $

DISTNAME=		Hermes-1.3.2
PKGREVISION=		1
WRKSRC=			${WRKDIR}/Hermes-1.3.2
CATEGORIES=		graphics
MASTER_SITES=		http://dark.x.dtu.dk/~mbn/clanlib/download/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanlib.org/hermes/
COMMENT=		Library for conversion of pixel graphics

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

.include "../../mk/bsd.pkg.mk"
