# $NetBSD: Makefile,v 1.4 2001/12/15 20:25:37 agc Exp $

DISTNAME=	itcl3.2
PKGNAME=	tcl-itcl-3.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/itcl/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://tcltk.com/itcl/
COMMENT=	[incr Tcl] object-oriented extension to Tcl/Tk

DEPENDS+=	tcl>=8.3.2:../../lang/tcl
DEPENDS+=	tk>=8.3.2:../../x11/tk

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS= --enable-shared

CONFIGURE_ENV+=	TCL_SRC_DIR="${_PKGSRCDIR}/lang/tcl/${WRKDIR:T}/tcl8.3.2"
CONFIGURE_ENV+=	TK_SRC_DIR="${_PKGSRCDIR}/x11/tk/${WRKDIR:T}/tk8.3.2"

post-extract:
	@${MV} -f ${WRKSRC}/iwidgets3.0.0/doc/dialog.n 			\
		${WRKSRC}/iwidgets3.0.0/doc/itcldialog.n
	@${MV} -f ${WRKSRC}/iwidgets3.0.0/doc/menubar.n 		\
		${WRKSRC}/iwidgets3.0.0/doc/itclmenubar.n
	@${MV} -f ${WRKSRC}/iwidgets2.2.0/doc/dialog.n 			\
		${WRKSRC}/iwidgets2.2.0/doc/itcldialog.n
	@${MV} -f ${WRKSRC}/iwidgets2.2.0/doc/menubar.n 		\
		${WRKSRC}/iwidgets2.2.0/doc/itclmenubar.n
	@if [ ! -e ${_PKGSRCDIR}/lang/tcl/${WRKDIR:T}/tcl8.3.2 ]; then	\
		cd ../../lang/tcl && ${MAKE} extract;			\
	fi
	@if [ ! -e ${_PKGSRCDIR}/x11/tk/${WRKDIR:T}/tk8.3.2 ]; then	\
		cd ../../x11/tk && ${MAKE} extract;			\
	fi

pre-clean:
	@cd ../../lang/tcl && ${MAKE} clean
	@cd ../../x11/tk && ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
