# $NetBSD: Makefile,v 1.8 2001/01/24 18:44:57 he Exp $
#

DISTNAME=	tclgdbm-0.8
PKGNAME=	tcl-gdbm-0.8
CATEGORIES=	databases tcl
MASTER_SITES=	http://www.graphviz.org/pub/tclgdbm/

MAINTAINER=	bouyer@netbsd.org

DEPENDS+=	tcl>=8.3.2:../../lang/tcl
DEPENDS+=	gdbm>=1.7.3:../../databases/gdbm

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
