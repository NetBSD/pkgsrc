# $NetBSD: Makefile,v 1.40 2013/12/29 19:26:36 tron Exp $

DISTNAME=	mdocml-1.12.2
CATEGORIES=	textproc devel
MASTER_SITES=	http://mdocml.bsd.lv/snapshots/

MAINTAINER=	kristaps@kth.se
HOMEPAGE=	http://mdocml.bsd.lv/
COMMENT=	Convert man pages from mdoc, man, and tbl to txt, html, ps, or pdf
LICENSE=	2-clause-bsd # not exactly, but near enough

MAKE_FLAGS+=	PREFIX=${PREFIX} DBLIB=${BDB_LIBS:Q}

CONFLICTS=	man-pages-[0-9]*

SUBST_CLASSES+=		roff
SUBST_STAGE.roff=	pre-build
SUBST_FILES.roff=	mandoc.1 mandoc.3
SUBST_FILES.roff+=	eqn.7 man.7 mdoc.7 tbl.7
SUBST_SED.roff=		-e 's,Xr roff,Xr mandoc-roff,g'

.include "../../mk/bsd.fast.prefs.mk"

# Mac OS X and Solaris 10 and newer do not support static binaries.
.if ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS"
MAKE_FLAGS+=	STATIC=
.endif

post-extract:
	${CP} -p ${FILESDIR}/*.c ${WRKSRC}

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
