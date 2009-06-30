# $NetBSD: Makefile,v 1.14 2009/06/30 00:07:15 joerg Exp $

DISTNAME=	cgoban-1.9.12
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.igoweb.org/~wms/comp/cgoban/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://www.igoweb.org/~wms/comp/cgoban/index.html
COMMENT=	The complete goban.  A Go server client and sgf viewer/editor

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	${PKGMANDIR}/man6 share/misc

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
