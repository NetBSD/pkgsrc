# $NetBSD: Makefile,v 1.41 2012/03/07 15:29:52 wiz Exp $

DISTNAME=	gif2png-2.5.5
CATEGORIES=	graphics converters
MASTER_SITES=	http://www.catb.org/~esr/gif2png/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/gif2png/
COMMENT=	Convert GIF files to PNG
LICENSE=	zlib

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES

PYTHON_PATCH_SCRIPTS+=	web2png

.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
