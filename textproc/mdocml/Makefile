# $NetBSD: Makefile,v 1.30 2012/05/12 07:37:51 wiz Exp $

DISTNAME=	mdocml-1.12.0
PKGREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	http://mdocml.bsd.lv/snapshots/

MAINTAINER=	kristaps@kth.se
HOMEPAGE=	http://mdocml.bsd.lv/
COMMENT=	Man page tool (mdoc macro compiler)
LICENSE=	2-clause-bsd # not exactly, but near enough

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=		PREFIX=${PREFIX} DBLIB=${BDB_LIBS:Q}

CONFLICTS=		man-pages-[0-9]*

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
