# $NetBSD: Makefile,v 1.7 2001/02/16 14:38:39 wiz Exp $
#

DISTNAME=		libstroke-0.3
PKGNAME=		libstroke-0.3nb1
CATEGORIES=		devel
MASTER_SITES=		http://www.etla.net/libstroke/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.etla.net/libstroke/
COMMENT=		Stroke translation library

DEPENDS+=		tcl>=8.3.2:../../lang/tcl

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11=		YES

CONFIGURE_ENV+=		X_CFLAGS="-I${LOCALBASE}/include"

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
