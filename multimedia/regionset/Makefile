# $NetBSD: Makefile,v 1.5 2008/03/04 19:32:30 jlam Exp $
#

DISTNAME=		regionset-0.1
CATEGORIES=		multimedia
MASTER_SITES=		http://linvdr.org/download/regionset/

HOMEPAGE=		http://linvdr.org/download/regionset/
COMMENT=		Read and modify DVD drive region code

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-* Linux-*-* DragonFly-*-*

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/regionset ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
