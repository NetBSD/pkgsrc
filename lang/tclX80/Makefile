# $NetBSD: Makefile,v 1.12 2000/06/01 11:23:34 rh Exp $
#

DISTNAME=	tclX8.0.4
PKGNAME=	tclX-8.0.4
CATEGORIES=	lang x11
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/tclx-distrib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.neosoft.com/TclX/

DEPENDS+=	tk-8.0.5:../../x11/tk80

USE_X11=		yes
USE_PKGLIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared --with-tk
CONFIGURE_ENV+=		TCL_SHLIB_LD_LIBS=-L${PREFIX}/lib

WRKSRC=			${WRKDIR}/tclX8.0.4/unix

.include "../../mk/bsd.pkg.mk"
