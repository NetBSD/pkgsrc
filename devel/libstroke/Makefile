# $NetBSD: Makefile,v 1.1.1.1 2000/01/02 16:41:05 rh Exp $
#

DISTNAME=		libstroke-0.3
CATEGORIES=		devel
MASTER_SITES=		http://www.etla.net/libstroke/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.etla.net/libstroke/

DEPENGS+=		tcl-8.0.5:../../lang/tcl80

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11=		YES

CONFIGURE_ENV+=		X_CFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl8.0"

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
