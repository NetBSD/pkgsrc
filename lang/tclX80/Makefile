# $NetBSD: Makefile,v 1.8 1999/04/05 22:55:36 tron Exp $
#

DISTNAME=	tclX8.0.4
PKGNAME=	tclX-8.0.4
CATEGORIES=	lang x11
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/tclx-distrib/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.neosoft.com/TclX/

DEPENDS+=	tk-8.0.5:../../x11/tk80

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared --with-tk
CONFIGURE_ENV+=		TCL_SHLIB_LD_LIBS=-L${PREFIX}/lib

WRKSRC=			${WRKDIR}/tclX8.0.4/unix
MAKE_ENV+=		INSTALL_DATA="${INSTALL_DATA}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}"

.include "../../mk/bsd.pkg.mk"
