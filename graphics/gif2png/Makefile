# $NetBSD: Makefile,v 1.52 2015/09/08 18:52:56 joerg Exp $

DISTNAME=	gif2png-2.5.11
PKGREVISION=	1
CATEGORIES=	graphics converters
MASTER_SITES=	http://www.catb.org/~esr/gif2png/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/gif2png/
COMMENT=	Convert GIF files to PNG
LICENSE=	zlib

REPLACE_PYTHON+=	web2png

LDFLAGS=	${COMPILER_RPATH_FLAG}${PREFIX}/lib -L${PREFIX}/lib
BUILD_MAKE_FLAGS=	LDFLAGS=${LDFLAGS:Q}
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${MV} ${DESTDIR}$(PREFIX)/share/man/man1/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
