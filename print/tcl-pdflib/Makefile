# $NetBSD: Makefile,v 1.2 2001/12/03 08:14:21 jlam Exp $

.include "../pdflib/Makefile.common"

PKGNAME=		tcl-pdflib-${PDFLIB_BASE_VERS}
COMMENT=		Tcl interface to PDFlib for generating PDF files

USE_BUILDLINK_ONLY=		YES
BUILDLINK_DEPENDS.pdflib=	pdflib>=${PDFLIB_BASE_VERS}

CONFIGURE_ARGS+=	--with-tcl=${TCLSH}
CONFIGURE_ARGS+=        --with-tclincl="${BUILDLINK_DIR}/include"
TCLSH=                  ${LOCALBASE}/bin/tclsh

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

.include "../pdflib/buildlink.mk"
.include "../../lang/tcl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
