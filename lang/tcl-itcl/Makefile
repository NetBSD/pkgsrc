# $NetBSD: Makefile,v 1.1.1.1 2001/02/23 20:36:24 jtb Exp $

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

.include "../../mk/bsd.pkg.mk"
