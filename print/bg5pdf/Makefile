# $NetBSD: Makefile,v 1.21 2010/02/10 19:17:44 joerg Exp $

DISTNAME=	bg5pdf-1.0.0
PKGREVISION=	8
CATEGORIES=	print chinese
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	rxg@NetBSD.org
# HOMEPAGE=	http://students.washington.edu/cschin/bg5ps/bg5pdf/
COMMENT=	Wrap big5 encoding text file into PDF file by using PDFlib

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=				${WRKDIR}/bg5pdf
PY_PATCHPLIST=			yes
PYTHON_PATCH_SCRIPTS=		bg5pdf

INSTALLATION_DIRS=	bin ${PYSITELIB}

MAKE_ENV+=	PYINC=${PYINC:Q} PYSITELIB=${PYSITELIB:Q}

post-extract:
	${RM} -f ${WRKSRC}/bg5pdflib.so

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
