# $NetBSD: Makefile,v 1.9 2002/07/16 14:48:03 agc Exp $

DISTNAME=		Hermes-1.3.2
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://dark.x.dtu.dk/~mbn/clanlib/download/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanlib.org/hermes/
COMMENT=		Library for conversion of pixel graphics

WRKSRC=			${WRKDIR}/Hermes-1.3.2

USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
MAKE_ENV=		INSTALL_PROGRAM_DIR="${INSTALL_PROGRAM_DIR}"

.include "../../mk/bsd.pkg.mk"
