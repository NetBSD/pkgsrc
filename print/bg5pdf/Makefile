# $NetBSD: Makefile,v 1.43 2026/08/04 20:29:13 wiz Exp $

DISTNAME=	bg5pdf-1.0.0
PKGREVISION=	23
CATEGORIES=	print chinese
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	rxg@NetBSD.org
# HOMEPAGE=	http://students.washington.edu/cschin/bg5ps/bg5pdf/
COMMENT=	Wrap big5 encoding text file into PDF file by using PDFlib

# The package is a confusing mix of GPL and pdflib license.
# Err on the side of caution until this is understood.
LICENSE=		aladdin-license AND gnu-gpl-v2
RESTRICTED=		"No clear permission to redistribute".
NO_SOURCE_ON_FTP=	${RESTRICTED}
NO_SOURCE_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

PYTHON_VERSIONS_ACCEPTED=	27

WRKSRC=		${WRKDIR}/bg5pdf
PY_PATCHPLIST=	yes
REPLACE_PYTHON=	bg5pdf

INSTALLATION_DIRS=	bin ${PYSITELIB}

MAKE_ENV+=	PYINC=${PYINC:Q} PYSITELIB=${PYSITELIB:Q}

post-extract:
	${RM} -f ${WRKSRC}/bg5pdflib.so

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
