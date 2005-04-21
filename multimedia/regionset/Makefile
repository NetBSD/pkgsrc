# $NetBSD: Makefile,v 1.2 2005/04/21 14:44:24 minskim Exp $
#

DISTNAME=		regionset-0.1
CATEGORIES=		multimedia
MASTER_SITES=		http://linvdr.org/download/regionset/

MAINTAINER=		rumble@NetBSD.org
HOMEPAGE=		http://linvdr.org/download/regionset/
COMMENT=		Read and modify DVD drive region code

PKG_INSTALLATION_TYPES=	overwrite pkgviews

ONLY_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-* Linux-*-*

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/regionset ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
