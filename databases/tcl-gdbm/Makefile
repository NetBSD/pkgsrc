# $NetBSD: Makefile,v 1.18 2005/09/28 20:52:19 rillig Exp $
#

DISTNAME=	tclgdbm-0.10
PKGNAME=	tcl-gdbm-0.10
PKGREVISION=	1
CATEGORIES=	databases tcl
MASTER_SITES=	http://www.graphviz.org/pub/tclgdbm/

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Tcl interface to gdbm - GNU database manager

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CFLAGS+=		-I${LOCALBASE}/include		# gdbm.h
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}

.include "../../databases/gdbm/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
