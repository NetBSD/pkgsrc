# $NetBSD: Makefile,v 1.1.1.1 2002/07/12 20:13:39 wiz Exp $
#

DISTNAME=	bg5pdf-1.0.0
CATEGORIES=	print chinese
MASTER_SITES=	http://students.washington.edu/cschin/bg5ps/bg5pdf/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://students.washington.edu/cschin/bg5ps/bg5pdf/
COMMENT=	wrap big5 encoding text file into PDF file by using PDFlib

PYTHON_VERSIONS_ACCEPTED=	21
PYBINMODULE=			# defined
PY_PATCHPLIST=			yes
PYTHON_PATCH_SCRIPTS=		bg5pdf

MAKE_ENV+=	PYINC=${PYINC} PYSITELIB=${PYSITELIB}

WRKSRC=		${WRKDIR}/bg5pdf

post-extract:
	${RM} -f ${WRKSRC}/bg5pdflib.so

.include "../../lang/python/application.buildlink.mk"
.include "../../lang/python/extension.buildlink.mk"
.include "../../print/pdflib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
