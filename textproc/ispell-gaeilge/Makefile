# $NetBSD: Makefile,v 1.13 2012/02/16 19:51:23 hans Exp $

DISTNAME=	ispell-gaeilge-2.0
CATEGORIES=	textproc
MASTER_SITES=	http://borel.slu.edu/~kps/ispell/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://borel.slu.edu/~kps/ispell/
COMMENT=	Irish language support for ispell

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

INSTALLATION_DIRS=	lib

MAKE_ENV+=	INSTALL=${TOOLS_PATH.install}

.include "../../mk/bsd.pkg.mk"
