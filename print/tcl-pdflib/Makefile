# $NetBSD: Makefile,v 1.21 2011/01/13 13:39:15 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../print/pdflib/Makefile.common"

PKGNAME=		tcl-pdflib-${PDFLIB_BASE_VERS}
PKGREVISION=		11
COMMENT=		Tcl interface to PDFlib for generating PDF files

BUILDLINK_API_DEPENDS.pdflib+=	pdflib>=${PDFLIB_BASE_VERS}

CONFIGURE_ARGS+=	--with-tcl=${TCLSH:Q}
CONFIGURE_ARGS+=	--with-tclincl="${BUILDLINK_PREFIX.tcl}/include"
CONFIGURE_ARGS+=	--with-tclpkg="${PREFIX}/lib/tcl8.4"
TCLSH=			${BUILDLINK_PREFIX.tcl}/bin/tclsh

BUILD_DIRS=		bind/tcl

pre-build:
	${TOUCH} ${WRKSRC}/pdflib/libpdf.la

.include "../../print/pdflib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
