# $NetBSD: Makefile,v 1.13 2003/07/21 16:54:07 martti Exp $
#

.include "../../lang/tcl-expect/Makefile.common"

PKGNAME=	tk-expect-${EXPECT_VERSION}
CATEGORIES=	lang

MAINTAINER=	jwise@NetBSD.org
COMMENT=	Tcl interpreter with both the expect and tk extensions built in

DEPENDS+=	tk>=8.3.2:../../x11/tk
DEPENDS+=	tcl-expect-${EXPECT_VERSION}:../../lang/tcl-expect

CONFIGURE_ARGS= --enable-shared \
		--with-tclconfig=${PREFIX}/lib \
		--with-tkconfig=${PREFIX}/lib \
		--with-tclinclude=${PREFIX}/include/tcl \
		--with-tkinclude=${PREFIX}/include/tk \

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/expectk ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/expectk.man ${PREFIX}/man/man1/expectk.1

.include "../../mk/bsd.pkg.mk"
