# $NetBSD: Makefile,v 1.36 2010/02/10 19:17:39 joerg Exp $

DISTNAME=	gif2png-2.5.2
PKGREVISION=	1
CATEGORIES=	graphics converters
MASTER_SITES=	http://www.catb.org/~esr/gif2png/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/gif2png/
COMMENT=	Convert GIF files to PNG

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES

PYTHON_PATCH_SCRIPTS+=	web2png

.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
