# $NetBSD: Makefile,v 1.9 2004/10/03 00:18:07 tv Exp $

.include "../pdflib/Makefile.common"

PKGNAME=		tcl-pdflib-${PDFLIB_BASE_VERS}
PKGREVISION=		3
COMMENT=		Tcl interface to PDFlib for generating PDF files

BUILDLINK_DEPENDS.pdflib=	pdflib>=${PDFLIB_BASE_VERS}

CONFIGURE_ARGS+=	--with-tcl=${TCLSH}
CONFIGURE_ARGS+=        --with-tclincl="${BUILDLINK_PREFIX.tcl}/include"
CONFIGURE_ARGS+=        --with-tclpkg="${PREFIX}/lib/tcl8.4"
TCLSH=                  ${BUILDLINK_PREFIX.tcl}/bin/tclsh

DIRS_TO_BUILD=		bind/tcl

pre-build:
	${TOUCH} ${WRKSRC}/pdflib/libpdf.la

do-build:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${ALL_TARGET}
.endfor

do-install:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}
.endfor

.include "../pdflib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
