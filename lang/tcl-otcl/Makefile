# $NetBSD: Makefile,v 1.1.1.1 2002/08/28 09:57:35 seb Exp $

DISTNAME=	otcl-1.0a8
PKGNAME=	tcl-${DISTNAME:S/a/rc/}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=otcl-tclcl/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://otcl-tclcl.sourceforge.net/otcl/
COMMENT=	MIT Object Tcl

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_BUILDLINK2=	yes
USE_X11=	yes

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}

CPPFLAGS+=	-I${BUILDLINK_PREFIX.tcl}/include/tcl/generic

HTMLDOCS=	CHANGES.html autoload.html capi.html class.html object.html \
		tutorial.html
DOCS=		otcl-paper.ps.gz
HTMLDOCDIR=	${PREFIX}/share/doc/html/tcl/otcl
DOCDIR=		${PREFIX}/share/doc/tcl/otcl

post-install:
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
.for _file_ in ${HTMLDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${_file_} ${HTMLDOCDIR}
.endfor
.for _file_ in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${_file_} ${DOCDIR}
.endfor

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
