# $NetBSD: Makefile,v 1.7 2014/10/09 14:06:43 wiz Exp $
#

DISTNAME=		regionset-0.1
CATEGORIES=		multimedia
MASTER_SITES=		http://linvdr.org/download/regionset/

HOMEPAGE=		http://linvdr.org/download/regionset/
COMMENT=		Read and modify DVD drive region code

ONLY_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-* Linux-*-* DragonFly-*-*

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/regionset ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
