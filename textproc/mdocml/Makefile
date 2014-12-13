# $NetBSD: Makefile,v 1.45 2014/12/13 15:52:53 wiz Exp $

DISTNAME=	mdocml-1.13.2
CATEGORIES=	textproc devel
MASTER_SITES=	http://mdocml.bsd.lv/snapshots/

MAINTAINER=	kristaps@kth.se
HOMEPAGE=	http://mdocml.bsd.lv/
COMMENT=	Convert man pages from mdoc, man, and tbl to txt, html, ps, or pdf
LICENSE=	2-clause-bsd # not exactly, but near enough

HAS_CONFIGURE=	yes

CONFLICTS=	man-pages-[0-9]*

SUBST_CLASSES+=		roff
SUBST_STAGE.roff=	pre-build
SUBST_FILES.roff=	mandoc.1 mandoc.3
SUBST_FILES.roff+=	eqn.7 man.7 mdoc.7 tbl.7
SUBST_SED.roff=		-e 's,Xr roff,Xr mandoc-roff,g'

.include "../../mk/bsd.fast.prefs.mk"

post-extract:
	${ECHO} PREFIX=${PREFIX} > ${WRKSRC}/configure.local
# Mac OS X and Solaris 10 and newer do not support static binaries.
.if ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS"
	${ECHO} STATIC= >> ${WRKSRC}/configure.local
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7 && mv roff.7 mandoc-roff.7

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
