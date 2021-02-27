# $NetBSD: Makefile,v 1.1 2021/02/27 21:09:40 leot Exp $

DISTNAME=	catpoint-v0.2
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	misc
MASTER_SITES=	ftp://bitreich.org/releases/catpoint/
EXTRACT_SUFX=	.tgz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	gopher://bitreich.org/1/scm/catpoint
COMMENT=	Simple presentation software written in curses
LICENSE=	gnu-gpl-v3

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

BUILDLINK_TRANSFORM+=	l:ncursesw:${BUILDLINK_LIBNAME.curses}

USE_LANGUAGES=	c99

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
