# $NetBSD: Makefile,v 1.1.1.1 2000/08/24 19:53:32 jwise Exp $
#

DISTNAME=		tcl8.3.2
PKGNAME=		tcl-8.3.2
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.scriptics.com/pub/tcl/tcl8_3/

MAINTAINER=		jwise@netbsd.org
HOMEPAGE=		http://www.tcltk.com/

WRKSRC=			${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=		yes

USE_LIBTOOL=		yes

INSTALL_TARGET=		install

post-install:
	cd ${PREFIX}/bin && ${LN} -s tclsh8.3 tclsh
	${MKDIR} ${PREFIX}/include/tcl
	${MKDIR} ${PREFIX}/include/tcl/unix
	${MKDIR} ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/tclUnixPort.h ${PREFIX}/include/tcl/unix
	${INSTALL_DATA} ${WRKSRC}/../generic/tcl.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclCompile.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclDecls.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclIO.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclInitScript.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclInt.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclIntDecls.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclIntPlatDecls.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclMath.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclPlatDecls.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclPort.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclRegexp.h ${PREFIX}/include/tcl/generic

test:
	cd ${WRKSRC} && ${SETENV} LIBTOOL=${LIBTOOL} PREFIX=${PREFIX} ${MAKE} test

.include "../../mk/bsd.pkg.mk"
