# $NetBSD: Makefile,v 1.17 2012/10/06 11:54:32 asau Exp $

DISTNAME=	cgoban-1.9.14
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cgoban1/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://cgoban1.sourceforge.net/
COMMENT=	The complete goban.  A Go server client and sgf viewer/editor

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	${PKGMANDIR}/man6 share/misc

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
