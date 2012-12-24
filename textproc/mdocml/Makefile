# $NetBSD: Makefile,v 1.33 2012/12/24 12:53:17 ryoon Exp $

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

.include "../../mk/bsd.prefs.mk"

.if ${OS_VARIANT} == "SmartOS"
CFLAGS+=	-D__SmartOS__
.endif

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
