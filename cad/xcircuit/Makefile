# $NetBSD: Makefile,v 1.48 2018/11/14 22:21:08 kleink Exp $

DISTNAME=	xcircuit-3.9.72
PKGREVISION=	3
CATEGORIES=	cad graphics
MASTER_SITES=	http://opencircuitdesign.com/xcircuit/archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://opencircuitdesign.com/xcircuit/
COMMENT=	Drawing program for X11 (especially for circuits)
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_TOOLS+=	gmake pkg-config gs:run
GNU_CONFIGURE=	yes

EGDIR=		share/examples/xcircuit

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
INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${EGDIR}

post-extract:
	${MV} -f ${WRKSRC}/examples/.xcircuitrc ${WRKSRC}/examples/xcircuitrc
	${TOUCH} ${WRKSRC}/menudep.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/xcircuit.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/examples/*.* ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/xcircuitrc ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../lang/tcl/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
