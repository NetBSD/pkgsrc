# $NetBSD: Makefile,v 1.8 2001/05/24 02:58:15 jlam Exp $
#

DISTNAME=		tcl8.3.2
PKGNAME=		tcl-8.3.2nb2
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.scriptics.com/pub/tcl/tcl8_3/ \
			ftp://gd.tuwien.ac.at/languages/tcl/scriptics/tcl8_3/ \
			ftp://ftp.funet.fi/pub/languages/tcl/tcl/tcl8_3/ \
			ftp://ftp.mpi-sb.mpg.de/pub/tcl/mirror/ftp.scriptics.com/tcl8_3/

MAINTAINER=		jwise@netbsd.org
HOMEPAGE=		http://www.tcltk.com/
COMMENT=		Ousterhout's Tool Command Language, a scripting language

CONFLICTS+=		tclman80-*

WRKSRC=			${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=		yes

USE_LIBTOOL=		yes

INSTALL_TARGET=		install

post-install:
	cd ${PREFIX}/bin && ${LN} -s tclsh8.3 tclsh
	${INSTALL_DATA_DIR} ${PREFIX}/include/tcl
	${INSTALL_DATA_DIR} ${PREFIX}/include/tcl/unix
	${INSTALL_DATA_DIR} ${PREFIX}/include/tcl/generic
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
