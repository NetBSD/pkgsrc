# $NetBSD: Makefile,v 1.12 2003/01/28 03:41:02 markd Exp $
#

.include "Makefile.common"

PKGNAME=	tcl-expect-${EXPECT_VERSION}
CATEGORIES=	lang

MAINTAINER=	jwise@netbsd.org
COMMENT=	extensions to Tcl to support scripting of interactive programs

DEPENDS+=	tcl>=8.3.2:../../lang/tcl

CONFLICTS+=	expect-[0-9]*

CONFIGURE_ARGS= --enable-shared \
		--with-tclconfig=${PREFIX}/lib \
		--with-tclinclude=${PREFIX}/include/tcl \
		--without-x

.include "../../mk/bsd.pkg.mk"
