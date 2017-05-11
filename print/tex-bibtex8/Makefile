# $NetBSD: Makefile,v 1.3 2017/05/11 14:34:39 jperkin Exp $
#

DISTNAME=	tex-bibtex8-3.71
CATEGORIES=	print
MASTER_SITES=	http://mirrors.ctan.org/biblio/bibtex/8-bit/
DISTFILES=	bt371src.zip bt371csf.zip

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://mirrors.ctan.org/biblio/bibtex/8-bit/
COMMENT=	8-bit Implementation of BibTeX 0.99 with multilanguage support
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR} # More than one possibility -- please check manually.

MAKE_FILE=	unix.mak
BUILD_TARGET=	bibtex-exe
MAKE_FLAGS+=	CFLAGS=${CFLAGS.${PKGSRC_COMPILER}:Q}
MAKE_FLAGS+=	CSF_INPUT_PATH=${PREFIX}/${TEXMFDIR}/bibtex/csf
MAKE_FLAGS+=	BIB_INPUT_PATH=${PREFIX}/${TEXMFDIR}/bibtex/bib
MAKE_FLAGS+=	BST_INPUT_PATH=${PREFIX}/${TEXMFDIR}/bibtex/bst

CFLAGS.gcc=	-Wall -Wno-char-subscripts -funsigned-char
CFLAGS.pcc=	${CFLAGS.gcc}
CFLAGS.icc=	${CFLAGS.gcc}
CFLAGS.clang=	${CFLAGS.gcc}
CFLAGS.sunpro=	-xchar=u
CFLAGS.xlc=	-qchars=unsigned

TEXMFDIR=		share/texmf-dist
INSTALLATION_DIRS=	bin ${TEXMFDIR}/bibtex/csf

post-build:
	set -e; cd ${WRKSRC}; \
	iconv -f cp866 -t koi8-r cp866rus.csf > koi8r.csf; \
	iconv -f cp866 -t cp1251 cp866rus.csf > cp1251rus.csf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bibtex ${DESTDIR}${PREFIX}/bin/bibtex8
	${INSTALL_DATA} ${WRKSRC}/*.csf ${DESTDIR}${PREFIX}/${TEXMFDIR}/bibtex/csf

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
