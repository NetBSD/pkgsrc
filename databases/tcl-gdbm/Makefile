# $NetBSD: Makefile,v 1.5 2000/08/29 21:05:46 jwise Exp $
#

DISTNAME=	tclgdbm-0.8
PKGNAME=	tcl-gdbm-0.8
CATEGORIES=	databases tcl
MASTER_SITES=	http://www.graphviz.org/pub/tclgdbm/

MAINTAINER=	bouyer@netbsd.org

DEPENDS+=	tcl-8.3.2:../../lang/tcl80
DEPENDS+=	gdbm>=1.7.3:../../databases/gdbm

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
