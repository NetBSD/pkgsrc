# $NetBSD: Makefile,v 1.3.2.1 2002/07/01 17:45:07 jlam Exp $

.include "../pdflib/Makefile.common"

PKGNAME=		tcl-pdflib-${PDFLIB_BASE_VERS}
PKGREVISION=		1
COMMENT=		Tcl interface to PDFlib for generating PDF files

BUILDLINK_DEPENDS.pdflib=	pdflib>=${PDFLIB_BASE_VERS}

USE_BUILDLINK2=		YES
CONFIGURE_ARGS+=	--with-tcl=${TCLSH}
CONFIGURE_ARGS+=        --with-tclincl="${BUILDLINK_PREFIX.tcl}/include"
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

.include "../pdflib/buildlink2.mk"
.include "../../lang/tcl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
