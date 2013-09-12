# $NetBSD: Makefile,v 1.35 2013/09/12 10:33:29 jperkin Exp $

DISTNAME=	mdocml-1.12.0
PKGREVISION=	3
CATEGORIES=	textproc devel
MASTER_SITES=	http://mdocml.bsd.lv/snapshots/

MAINTAINER=	kristaps@kth.se
HOMEPAGE=	http://mdocml.bsd.lv/
COMMENT=	Man page tool (mdoc macro compiler)
LICENSE=	2-clause-bsd # not exactly, but near enough

MAKE_FLAGS+=	PREFIX=${PREFIX} DBLIB=${BDB_LIBS:Q}

CONFLICTS=	man-pages-[0-9]*

SUBST_CLASSES+=		roff
SUBST_STAGE.roff=	pre-build
SUBST_FILES.roff=	mandoc.1 mandoc.3
SUBST_FILES.roff+=	eqn.7 man.7 mdoc.7 tbl.7
SUBST_SED.roff=		-e 's,Xr roff,Xr mandoc-roff,g'

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
