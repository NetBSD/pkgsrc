# $NetBSD: Makefile,v 1.5 2000/08/14 19:09:23 wiz Exp $

DISTNAME=		Hermes-1.2.6-2
PKGNAME=		Hermes-1.2.6.2
WRKSRC=			${WRKDIR}/Hermes-1.2.6
CATEGORIES=		graphics
MASTER_SITES=		http://hermes.terminal.at/files/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanlib.org/hermes/

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
MAKE_ENV=		INSTALL_PROGRAM_DIR="${INSTALL_PROGRAM_DIR}"

.include "../../mk/bsd.pkg.mk"
