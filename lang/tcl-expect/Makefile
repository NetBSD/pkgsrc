# $NetBSD: Makefile,v 1.15 2004/03/08 19:52:51 minskim Exp $
#

.include "Makefile.common"

PKGNAME=	tcl-expect-${EXPECT_VERSION}
CATEGORIES=	lang

MAINTAINER=	jwise@NetBSD.org
COMMENT=	Extensions to Tcl to support scripting of interactive programs

DEPENDS+=	tcl>=8.3.2:../../lang/tcl83

CONFLICTS+=	expect-[0-9]*

CONFIGURE_ARGS= --enable-shared \
		--with-tclconfig=${PREFIX}/lib \
		--with-tclinclude=${PREFIX}/include/tcl \
		--without-x

.include "../../mk/bsd.pkg.mk"
