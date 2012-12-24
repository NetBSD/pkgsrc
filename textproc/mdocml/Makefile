# $NetBSD: Makefile,v 1.34 2012/12/24 13:40:18 jperkin Exp $

DISTNAME=	mdocml-1.12.0
PKGREVISION=	2
CATEGORIES=	textproc devel
MASTER_SITES=	http://mdocml.bsd.lv/snapshots/

MAINTAINER=	kristaps@kth.se
HOMEPAGE=	http://mdocml.bsd.lv/
COMMENT=	Man page tool (mdoc macro compiler)
LICENSE=	2-clause-bsd # not exactly, but near enough

MAKE_FLAGS+=		PREFIX=${PREFIX} DBLIB=${BDB_LIBS:Q}

CONFLICTS=		man-pages-[0-9]* groff-[0-9]*

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
