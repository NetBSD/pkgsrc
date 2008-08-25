# $NetBSD: Makefile,v 1.1.1.1 2008/08/25 18:17:56 bjs Exp $
#

DISTNAME=	vigra1.6.0
PKGNAME=	${DISTNAME:C/^[[:alpha:]]+/&-/}
CATEGORIES=	graphics
MASTER_SITES=	http://kogs-www.informatik.uni-hamburg.de/~koethe/vigra/

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://kogs-www.informatik.uni-hamburg.de/~koethe/vigra/
COMMENT=	Computer vision library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--with-cc=${CC:Q} --with-cxx=${CXX:Q}
CONFIGURE_ARGS+=	--docdir=${PREFIX:Q}/share/doc/${PKGBASE:Q}
CONFIGURE_HAS_MANDIR=	no

.if defined(PKG_DEVELOPER)
CFLAGS+=		-Wall
.endif

INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin
INSTALL_MAKE_FLAGS+=	docdir=${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
INSTALL_MAKE_FLAGS+=	includedir=${DESTDIR}${PREFIX}/include
INSTALL_MAKE_FLAGS+=	libdir=${DESTDIR}${PREFIX}/lib


.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
