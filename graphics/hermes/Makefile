# $NetBSD: Makefile,v 1.6 2000/12/15 00:38:43 garbled Exp $

DISTNAME=		Hermes-1.3.2
WRKSRC=			${WRKDIR}/Hermes-1.3.2
CATEGORIES=		graphics
MASTER_SITES=		http://dark.x.dtu.dk/~mbn/clanlib/download/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanlib.org/hermes/

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
MAKE_ENV=		INSTALL_PROGRAM_DIR="${INSTALL_PROGRAM_DIR}"

.include "../../mk/bsd.pkg.mk"
