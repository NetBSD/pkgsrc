# $NetBSD: Makefile,v 1.16 2004/03/11 07:16:45 minskim Exp $
#

.include "Makefile.common"

PKGNAME=	tcl-expect-${EXPECT_VERSION}
PKGREVISION=	1
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
