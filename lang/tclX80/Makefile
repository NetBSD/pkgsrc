# $NetBSD: Makefile,v 1.6 1999/04/01 13:38:44 agc Exp $
#

DISTNAME=	tclX8.0.2
PKGNAME=	tclX-8.0.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/tclx-distrib/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.neosoft.com/TclX/

DEPENDS+=	tk-8.0.5:../../x11/tk80

WRKSRC=		${WRKDIR}/tclX8.0.2/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared --with-tk
CONFIGURE_ENV+=	PREFIX=${PREFIX} TCL_SHLIB_LD_LIBS=-L${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
