# $NetBSD: Makefile,v 1.12 2003/07/17 21:29:07 grant Exp $
#

DISTNAME=	tclgdbm-0.8
PKGNAME=	tcl-gdbm-0.8
PKGREVISION=	1
CATEGORIES=	databases tcl
MASTER_SITES=	http://www.graphviz.org/pub/tclgdbm/

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Tcl interface to gdbm - GNU database manager

DEPENDS+=	tcl>=8.3.2:../../lang/tcl
DEPENDS+=	gdbm>=1.8.3:../../databases/gdbm

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CFLAGS+=		-I${LOCALBASE}/include		# gdbm.h

.include "../../mk/bsd.pkg.mk"
