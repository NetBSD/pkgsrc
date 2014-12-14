# $NetBSD: Makefile,v 1.50 2014/12/14 15:49:34 wiz Exp $

DISTNAME=	gif2png-2.5.10
CATEGORIES=	graphics converters
MASTER_SITES=	http://www.catb.org/~esr/gif2png/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/gif2png/
COMMENT=	Convert GIF files to PNG
LICENSE=	zlib

GNU_CONFIGURE=		YES

REPLACE_PYTHON+=	web2png

.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
