# $NetBSD: Makefile,v 1.13 2004/10/03 00:15:03 tv Exp $

DISTNAME=	itcl3.2
PKGNAME=	tcl-itcl-3.2
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/itcl/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tcltk.com/itcl/
COMMENT=	[incr Tcl] object-oriented extension to Tcl/Tk

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	tcl-itcl-current-[0-9]*      

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS= --with-tcl=${BUILDLINK_PREFIX.tcl}/lib	\
		--with-tk=${BUILDLINK_PREFIX.tk}/lib	\
		--enable-shared

MAKE_ENV+=	TCL_HEADER_DIR=${BUILDLINK_PREFIX.tcl}/include/tcl

post-extract:
	@${MV} -f ${WRKSRC}/iwidgets3.0.0/doc/dialog.n 			\
		${WRKSRC}/iwidgets3.0.0/doc/itcldialog.n
	@${MV} -f ${WRKSRC}/iwidgets3.0.0/doc/menubar.n 		\
		${WRKSRC}/iwidgets3.0.0/doc/itclmenubar.n
	@${MV} -f ${WRKSRC}/iwidgets3.0.0/doc/tabset.n			\
		${WRKSRC}/iwidgets3.0.0/doc/itcltabset.n
	@${MV} -f ${WRKSRC}/iwidgets3.0.0/doc/watch.n			\
		${WRKSRC}/iwidgets3.0.0/doc/itclwatch.n
	@${MV} -f ${WRKSRC}/iwidgets2.2.0/doc/dialog.n 			\
		${WRKSRC}/iwidgets2.2.0/doc/itcldialog.n
	@${MV} -f ${WRKSRC}/iwidgets2.2.0/doc/menubar.n 		\
		${WRKSRC}/iwidgets2.2.0/doc/itclmenubar.n
	@${MV} -f ${WRKSRC}/iwidgets2.2.0/doc/tabset.n			\
		${WRKSRC}/iwidgets2.2.0/doc/itcltabset.n

.include "../../lang/tcl83/buildlink3.mk"
.include "../../x11/tk83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
