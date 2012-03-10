# $NetBSD: Makefile,v 1.29 2012/03/10 16:06:35 joerg Exp $

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

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
