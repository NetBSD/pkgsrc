# $NetBSD: Makefile,v 1.44 2014/12/17 06:35:13 obache Exp $

DISTNAME=	xcircuit-3.7.50
PKGREVISION=	2
CATEGORIES=	cad graphics
MASTER_SITES=	http://opencircuitdesign.com/xcircuit/archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://opencircuitdesign.com/xcircuit/
COMMENT=	Drawing program for X11 (especially for circuits)
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_TOOLS+=	gmake gs:run
GNU_CONFIGURE=	yes

.include "../../lang/tcl/Makefile.version"
.include "../../x11/tk/Makefile.version"

CONFIGURE_ARGS+=--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=--with-tk=${BUILDLINK_PREFIX.tk}/lib
CONFIGURE_ARGS+=--with-tclincls=${BUILDLINK_PREFIX.tcl}/include
CONFIGURE_ARGS+=--with-tcllibs=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=--with-tkincls=${BUILDLINK_PREFIX.tk}/include
CONFIGURE_ARGS+=--with-tklibs=${BUILDLINK_PREFIX.tk}/lib
#CFLAGS+=	-DBUILTINS_DIR=${PREFIX}/lib/${DISTNAME:C/\.[^\.]*$//}

BUILD_TARGET=	tcl
INSTALL_TARGET= install-tcl
INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/examples/xcircuit

post-extract:
	${MV} -f ${WRKSRC}/examples/.xcircuitrc ${WRKSRC}/examples/xcircuitrc
	${TOUCH} ${WRKSRC}/menudep.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/*.* ${DESTDIR}${PREFIX}/share/examples/xcircuit/
	${INSTALL_DATA} ${WRKSRC}/examples/xcircuitrc ${DESTDIR}${PREFIX}/share/examples/xcircuit/

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
