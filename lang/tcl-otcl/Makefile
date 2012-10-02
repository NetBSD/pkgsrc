# $NetBSD: Makefile,v 1.24 2012/10/02 20:11:55 asau Exp $

DISTNAME=	otcl-src-1.14
PKGNAME=	tcl-${DISTNAME:S/-src//}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=otcl-tclcl/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://otcl-tclcl.sourceforge.net/otcl/
COMMENT=	MIT Object Tcl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

.include "../../lang/tcl/Makefile.version"
.include "../../x11/tk/Makefile.version"

CONFIGURE_ARGS+=	V_LIBS="`${CONFIG_SHELL} -c '. ${TCLCONFIG_SH}; ${ECHO} $$TCL_LIBS'`"
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}
CONFIGURE_ARGS+=	--with-tcl-ver=${TCL_VERSION}
CONFIGURE_ARGS+=	--with-tk-ver=${TK_VERSION}

CPPFLAGS+=	-I${BUILDLINK_PREFIX.tcl}/include/tcl/generic

DOCS=		autoload.html capi.html class.html object.html \
		tutorial.html otcl-paper.ps.gz
DOCDIR=		${PREFIX}/share/doc/tcl/otcl

INSTALLATION_DIRS=	bin include lib ${DOCDIR}

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/CHANGES.html ${DESTDIR}${DOCDIR}
.for _file_ in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${_file_} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
