# $NetBSD: Makefile,v 1.6 2003/07/21 17:16:16 martti Exp $
#

DISTNAME=	bg5pdf-1.0.0
WRKSRC=		${WRKDIR}/bg5pdf
CATEGORIES=	print chinese
MASTER_SITES=	http://students.washington.edu/cschin/bg5ps/bg5pdf/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://students.washington.edu/cschin/bg5ps/bg5pdf/
COMMENT=	Wrap big5 encoding text file into PDF file by using PDFlib

USE_BUILDLINK2=			yes
PYTHON_VERSIONS_ACCEPTED=	21
PYBINMODULE=			# defined
PY_PATCHPLIST=			yes
PYTHON_PATCH_SCRIPTS=		bg5pdf

MAKE_ENV+=	PYINC=${PYINC} PYSITELIB=${PYSITELIB}

post-extract:
	${RM} -f ${WRKSRC}/bg5pdflib.so

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../print/pdflib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
