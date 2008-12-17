# $NetBSD: Makefile,v 1.1.1.1 2008/12/17 11:56:26 obache Exp $

DISTNAME=	fdupes-1.40
CATEGORIES=	sysutils
MASTER_SITES=	http://netdial.caribe.net/~adrian2/programs/

MAINTAINER=	ef@math.uni-bonn.de
HOMEPAGE=	http://netdial.caribe.net/~adrian2/fdupes.html
COMMENT=	Program for identifying or deleting duplicate files

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
NO_CONFIGURE=	yes

MAKE_FLAGS=	INSTALLDIR=${PREFIX}/bin MANPAGEDIR=${PREFIX}/${PKGMANDIR}

BUILD_TARGET=		fdupes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
