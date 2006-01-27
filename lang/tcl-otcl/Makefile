# $NetBSD: Makefile,v 1.16 2006/01/27 01:18:19 minskim Exp $

DISTNAME=	otcl-1.11
PKGNAME=	tcl-${DISTNAME}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=otcl-tclcl/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://otcl-tclcl.sourceforge.net/otcl/
COMMENT=	MIT Object Tcl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	V_LIBS="`${CONFIG_SHELL} -c '. ${TCLCONFIG_SH}; ${ECHO} $$TCL_LIBS'`"
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}

CPPFLAGS+=	-I${BUILDLINK_PREFIX.tcl}/include/tcl/generic

DOCS=		autoload.html capi.html class.html object.html \
		tutorial.html otcl-paper.ps.gz
DOCDIR=		${PREFIX}/share/doc/tcl/otcl

INSTALLATION_DIRS=	bin include lib

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES.html ${DOCDIR}
.for _file_ in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${_file_} ${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
