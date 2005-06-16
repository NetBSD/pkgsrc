# $NetBSD: Makefile,v 1.5 2005/06/16 06:57:58 jlam Exp $
#

DISTNAME=		metacam-1.2
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.cheeseplant.org/pub/

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://www.cheeseplant.org/~daniel/pages/metacam.html
COMMENT=		Digital camera image meta-information reader

USE_TOOLS+=		gmake
BUILD_TARGET=		default
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/metacam ${PREFIX}/bin

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
