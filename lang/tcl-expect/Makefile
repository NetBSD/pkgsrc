# $NetBSD: Makefile,v 1.18 2004/10/30 05:21:42 minskim Exp $
#

.include "Makefile.common"

PKGNAME=	tcl-expect-${EXPECT_VERSION}
PKGREVISION=	3
CATEGORIES=	lang

MAINTAINER=	jwise@NetBSD.org
COMMENT=	Extensions to Tcl to support scripting of interactive programs

CONFLICTS+=	expect-[0-9]*

CONFIGURE_ARGS= --enable-shared \
		--with-tclconfig=${PREFIX}/lib \
		--with-tclinclude=${PREFIX}/include/tcl \
		--without-x

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
