# $NetBSD: Makefile,v 1.1.1.1 2004/10/02 04:03:34 simonb Exp $
#

DISTNAME=		metacam-1.2
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.cheeseplant.org/pub/

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://www.cheeseplant.org/~daniel/pages/metacam.html
COMMENT=		Digital camera image meta-information reader

USE_GNU_TOOLS+=		make
ALL_TARGET=		default

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/metacam ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
