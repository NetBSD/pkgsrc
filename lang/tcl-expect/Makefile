# $NetBSD: Makefile,v 1.20 2004/11/30 20:30:19 adam Exp $

.include "Makefile.common"

PKGNAME=	tcl-expect-${EXPECT_VERSION}
CATEGORIES=	lang

MAINTAINER=	jwise@NetBSD.org
COMMENT=	Extensions to Tcl to support scripting of interactive programs

CONFLICTS+=	expect-[0-9]*

CONFIGURE_ARGS= --enable-shared --without-x \
		--with-tclconfig=${PREFIX}/lib \
		--with-tclinclude=${PREFIX}/include/tcl

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
