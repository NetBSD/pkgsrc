# $NetBSD: Makefile,v 1.18 2005/04/08 11:54:15 adam Exp $

.include "../../lang/tcl-expect/Makefile.common"

PKGNAME=	tk-expect-${EXPECT_VERSION}
CATEGORIES=	lang

MAINTAINER=	jwise@NetBSD.org
COMMENT=	Tcl interpreter with both the expect and tk extensions built in

DEPENDS+=	tcl-expect>=${EXPECT_VERSION}:../../lang/tcl-expect

CONFIGURE_ARGS+= 	--enable-shared
CONFIGURE_ARGS+=	--with-tclconfig=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-tclinclude=${PREFIX}/include/tcl
CONFIGURE_ARGS+=	--with-tkconfig=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-tkinclude=${PREFIX}/include/tk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/expectk ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/expectk.man ${PREFIX}/man/man1/expectk.1

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
