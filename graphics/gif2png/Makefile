# $NetBSD: Makefile,v 1.46 2013/02/16 11:21:54 wiz Exp $

DISTNAME=	gif2png-2.5.8
PKGREVISION=	1
CATEGORIES=	graphics converters
MASTER_SITES=	http://www.catb.org/~esr/gif2png/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/gif2png/
COMMENT=	Convert GIF files to PNG
LICENSE=	zlib

GNU_CONFIGURE=		YES

PYTHON_PATCH_SCRIPTS+=	web2png

.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
