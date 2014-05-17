# $NetBSD: Makefile,v 1.48 2014/05/17 16:10:45 wiz Exp $

DISTNAME=	gif2png-2.5.8
PKGREVISION=	2
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
