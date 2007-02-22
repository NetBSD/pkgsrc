# $NetBSD: Makefile,v 1.22 2007/02/22 19:26:40 wiz Exp $

.include "../../lang/tcl-expect/Makefile.common"

PKGNAME=	tk-expect-${EXPECT_VERSION}
PKGREVISION=	1
CATEGORIES=	lang

MAINTAINER=	jwise@NetBSD.org
COMMENT=	Tcl interpreter with both the expect and tk extensions built in

DEPENDS+=	tcl-expect>=${EXPECT_VERSION}:../../lang/tcl-expect

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-tclconfig=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-tclinclude=${PREFIX}/include/tcl
CONFIGURE_ARGS+=	--with-tkconfig=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-tkinclude=${PREFIX}/include/tk

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/expectk ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/expectk.man ${PREFIX}/${PKGMANDIR}/man1/expectk.1

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
