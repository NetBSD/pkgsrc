# $NetBSD: Makefile,v 1.3 2004/04/24 22:46:11 jlam Exp $

DISTNAME=	src
PKGNAME=	unison-2.9.20
CATEGORIES=	net
MASTER_SITES=	http://www.cis.upenn.edu/~bcpierce/unison/download/beta-test/latest/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cis.upenn.edu/~bcpierce/unison/
COMMENT=	File-synchronization tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DIST_SUBDIR=	${PKGNAME_NOREV}

# docs: unison-manual.pdf/html/ps/dvi
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK3=	yes
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

post-install:
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
