# $NetBSD: Makefile,v 1.21 2005/04/08 11:54:04 adam Exp $

.include "Makefile.common"

PKGNAME=	tcl-expect-${EXPECT_VERSION}
CATEGORIES=	lang

MAINTAINER=	jwise@NetBSD.org
COMMENT=	Extensions to Tcl to support scripting of interactive programs

CONFLICTS+=	expect-[0-9]*

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-tclconfig=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-tclinclude=${PREFIX}/include/tcl
CONFIGURE_ARGS+= 	--without-x

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
