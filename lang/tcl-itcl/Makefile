# $NetBSD: Makefile,v 1.10 2004/03/08 20:27:14 minskim Exp $

DISTNAME=	itcl3.2
PKGNAME=	tcl-itcl-3.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/itcl/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tcltk.com/itcl/
COMMENT=	[incr Tcl] object-oriented extension to Tcl/Tk

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS= --enable-shared

CONFIGURE_ENV+=	TCL_SRC_DIR="${_PKGSRCDIR}/lang/tcl/${WRKDIR:T}/tcl8.3.4"
CONFIGURE_ENV+=	TK_SRC_DIR="${_PKGSRCDIR}/x11/tk/${WRKDIR:T}/tk8.3.4"

post-extract:
	@${MV} -f ${WRKSRC}/iwidgets3.0.0/doc/dialog.n 			\
		${WRKSRC}/iwidgets3.0.0/doc/itcldialog.n
	@${MV} -f ${WRKSRC}/iwidgets3.0.0/doc/menubar.n 		\
		${WRKSRC}/iwidgets3.0.0/doc/itclmenubar.n
	@${MV} -f ${WRKSRC}/iwidgets2.2.0/doc/dialog.n 			\
		${WRKSRC}/iwidgets2.2.0/doc/itcldialog.n
	@${MV} -f ${WRKSRC}/iwidgets2.2.0/doc/menubar.n 		\
		${WRKSRC}/iwidgets2.2.0/doc/itclmenubar.n
	@if [ ! -e ${_PKGSRCDIR}/lang/tcl/${WRKDIR:T}/tcl8.3.4 ]; then	\
		cd ../../lang/tcl83 && ${MAKE} extract;			\
	fi
	@if [ ! -e ${_PKGSRCDIR}/x11/tk/${WRKDIR:T}/tk8.3.4 ]; then	\
		cd ../../x11/tk83 && ${MAKE} extract;			\
	fi

pre-clean:
	@cd ../../lang/tcl83 && ${MAKE} clean
	@cd ../../x11/tk83 && ${MAKE} clean

.include "../../lang/tcl83/buildlink2.mk"
.include "../../x11/tk83/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
