# $NetBSD: Makefile,v 1.34 2018/08/22 09:46:15 wiz Exp $

.include "../../print/pdflib/Makefile.common"

PKGNAME=		tcl-pdflib-${PDFLIB_BASE_VERS}
PKGREVISION=		19
COMMENT=		Tcl interface to PDFlib for generating PDF files

MAKE_JOBS_SAFE=		no

BUILDLINK_API_DEPENDS.pdflib+=	pdflib>=${PDFLIB_BASE_VERS}

CONFIGURE_ARGS+=	--with-tcl=${TCLSH:Q}
CONFIGURE_ARGS+=	--with-tclincl="${BUILDLINK_PREFIX.tcl}/include"
CONFIGURE_ARGS+=	--with-tclpkg="${PREFIX}/lib/tcl${TCL_BASEVER}"
TCLSH=			${BUILDLINK_PREFIX.tcl}/bin/tclsh

BUILD_DIRS=		bind/tcl

pre-build:
	${TOUCH} ${WRKSRC}/pdflib/libpdf.la

.include "../../print/pdflib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl/Makefile.version"

.include "../../mk/bsd.pkg.mk"
