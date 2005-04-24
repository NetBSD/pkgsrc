# $NetBSD: Makefile,v 1.8 2005/04/24 13:06:03 adrianp Exp $

DISTNAME=	unison-2.12.0
CATEGORIES=	net
MASTER_SITES=	http://www.cis.upenn.edu/~bcpierce/unison/download/beta-test/latest/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cis.upenn.edu/~bcpierce/unison/
COMMENT=	File-synchronization tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DIST_SUBDIR=	${PKGNAME_NOREV}
BUILDLINK_DEPENDS.ocaml+=	ocaml>=3.08.2

# docs: unison-manual.pdf/html/ps/dvi
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_GNU_TOOLS+=	make
MAKE_FLAGS+=	CFLAGS="" UISTYLE=text
MAKE_ENV+=	HOME=${WRKDIR}

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

SUBST_CLASSES=		x11
SUBST_STAGE.x11=	post-patch
SUBST_FILES.x11=	Makefile.OCaml
SUBST_SED.x11=		-e "s|/usr/X11R6|${X11BASE}|g"
SUBST_MESSAGE.x11=	"Fixing X11 paths."

post-install:
	@cd ${WRKSRC} && ./unison -doc install > INSTALL
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/BUGS.txt ${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/CONTRIB ${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/COPYING ${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/DEPENDENCIES.ps ${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/NEWS ${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/ROADMAP.txt ${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/TODO.txt ${PREFIX}/share/doc/unison

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
