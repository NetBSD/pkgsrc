# $NetBSD: Makefile,v 1.14 2000/09/01 17:58:04 jwise Exp $
#

DISTNAME=	tclX8.0.4
PKGNAME=	tclX-8.0.4
CATEGORIES=	lang x11
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/tclx-distrib/

BROKEN=		This package has not yet been updated to work with tcl-8.3.2.

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.neosoft.com/TclX/

DEPENDS+=	tk-8.0.5:../../x11/tk80

USE_X11=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared --with-tk
CONFIGURE_ENV+=		TCL_SHLIB_LD_LIBS=-L${PREFIX}/lib

WRKSRC=			${WRKDIR}/tclX8.0.4/unix

.include "../../mk/bsd.pkg.mk"
