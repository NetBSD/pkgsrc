# $NetBSD: Makefile,v 1.3 2005/03/10 14:27:20 tv Exp $
#

DISTNAME=		metacam-1.2
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.cheeseplant.org/pub/

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://www.cheeseplant.org/~daniel/pages/metacam.html
COMMENT=		Digital camera image meta-information reader

USE_GNU_TOOLS+=		make
BUILD_TARGET=		default

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/metacam ${PREFIX}/bin

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
