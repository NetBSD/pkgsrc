# $NetBSD: Makefile,v 1.13 2005/12/05 20:50:50 rillig Exp $

DISTNAME=	unison-2.17.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.cis.upenn.edu/~bcpierce/unison/download/releases/beta/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://www.cis.upenn.edu/~bcpierce/unison/
COMMENT=	File-synchronization tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DIST_SUBDIR=	${PKGNAME_NOREV}
BUILDLINK_DEPENDS.ocaml+=	ocaml>=3.08.2

# docs: unison-manual.pdf/html/ps/dvi
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	gmake
MAKE_FLAGS+=	CFLAGS="" UISTYLE=text
MAKE_ENV+=	HOME=${WRKDIR:Q}

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
MAKE_FLAGS+=	NATIVE=true
.else
MAKE_FLAGS+=	NATIVE=false
.endif

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} != "none")
MAKE_FLAGS+=	THREADS=true
.endif

INSTALLATION_DIRS=	bin

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/BUGS.txt ${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/CONTRIB ${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/COPYING ${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/NEWS ${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/ROADMAP.txt ${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/TODO.txt ${PREFIX}/share/doc/unison

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
