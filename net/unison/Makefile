# $NetBSD: Makefile,v 1.14 2003/06/23 20:36:14 jtb Exp $
#

DISTNAME=	src
PKGNAME=	unison-2.9.1
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	net
MASTER_SITES=	http://www.cis.upenn.edu/~bcpierce/unison/download/stable/latest/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.cis.upenn.edu/~bcpierce/unison/
COMMENT=	file-synchronization tool

BUILD_DEPENDS=	ocaml>=3.00:../../lang/ocaml
BUILD_DEPENDS+=	bash>=2.05:../../shells/bash2

DIST_SUBDIR=	${PKGNAME_NOREV}

# docs: unison-manual.pdf/html/ps/dvi
USE_GMAKE=	yes
MAKE_FLAGS+=	CFLAGS="" UISTYLE=text
MAKE_ENV+=	HOME=${WRKDIR}

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} != "i386") || (${MACHINE_ARCH} != "powerpc") || (${MACHINE_ARCH} != "sparc")
MAKE_FLAGS+=	NATIVE=false
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
