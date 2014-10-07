# $NetBSD: Makefile,v 1.44 2014/10/07 16:47:36 adam Exp $

DISTNAME=	mdocml-1.13.1
PKGREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	http://mdocml.bsd.lv/snapshots/

MAINTAINER=	kristaps@kth.se
HOMEPAGE=	http://mdocml.bsd.lv/
COMMENT=	Convert man pages from mdoc, man, and tbl to txt, html, ps, or pdf
LICENSE=	2-clause-bsd # not exactly, but near enough

MAKE_FLAGS+=	PREFIX=${PREFIX}

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

post-install:
	cd ${DESTDIR}${PREFIX}/bin && mv preconv mandoc-preconv
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && mv preconv.1 mandoc-preconv.1
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7 && mv roff.7 mandoc-roff.7

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
