# $NetBSD: Makefile,v 1.11 2004/10/03 00:15:03 tv Exp $

DISTNAME=	otcl-1.8
PKGNAME=	tcl-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=otcl-tclcl/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://otcl-tclcl.sourceforge.net/otcl/
COMMENT=	MIT Object Tcl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_X11=	yes

CONFIGURE_ARGS+=	V_LIBS="`${CONFIG_SHELL} -c '. ${TCLCONFIG_SH}; echo $$TCL_LIBS'`"
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}

CPPFLAGS+=	-I${BUILDLINK_PREFIX.tcl}/include/tcl/generic

HTMLDOCS=	CHANGES.html autoload.html capi.html class.html object.html \
		tutorial.html
DOCS=		otcl-paper.ps.gz
HTMLDOCDIR=	${PREFIX}/share/doc/html/tcl/otcl
DOCDIR=		${PREFIX}/share/doc/tcl/otcl

INSTALLATION_DIRS=	bin include lib

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
.for _file_ in ${HTMLDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${_file_} ${HTMLDOCDIR}
.endfor
.for _file_ in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${_file_} ${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
