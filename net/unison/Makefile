# $NetBSD: Makefile,v 1.16 2003/07/17 22:51:59 grant Exp $

DISTNAME=	src
PKGNAME=	unison-2.9.1
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	net
MASTER_SITES=	http://www.cis.upenn.edu/~bcpierce/unison/download/stable/latest/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cis.upenn.edu/~bcpierce/unison/
COMMENT=	file-synchronization tool

BUILD_DEPENDS=	ocaml>=3.00:../../lang/ocaml

DIST_SUBDIR=	${PKGNAME_NOREV}

# docs: unison-manual.pdf/html/ps/dvi
USE_GMAKE=	yes
MAKE_FLAGS+=	CFLAGS="" UISTYLE=text
MAKE_ENV+=	HOME=${WRKDIR}

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
MAKE_FLAGS+=	NATIVE=true
.else
MAKE_FLAGS+=	NATIVE=false
.endif

.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} != "none")
MAKE_FLAGS+=	THREADS=true
.endif

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

.include "../../mk/bsd.pkg.mk"
