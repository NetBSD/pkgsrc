# $NetBSD: Makefile,v 1.6 2002/01/17 13:19:45 dmcmahill Exp $
#

DISTNAME=	src
PKGNAME=	unison-2.7.7
CATEGORIES=	net
MASTER_SITES=	http://www.cis.upenn.edu/~bcpierce/unison/download/stable/latest/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cis.upenn.edu/~bcpierce/unison/
COMMENT=	file-synchronization tool

BUILD_DEPENDS=	ocaml>=3.00:../../lang/ocaml

DIST_SUBDIR=	${PKGNAME}

# docs: unison-manual.pdf/html/ps/dvi
WRKSRC=		${WRKDIR}/${PKGNAME}
USE_GMAKE=	yes
MAKE_FLAGS+=	CFLAGS="" UISTYLE=text

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} != "i386")
# we don't have ocamlopt on non-i386 so don't try and use it
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
