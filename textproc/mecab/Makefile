# $NetBSD: Makefile,v 1.4 2008/06/15 09:51:59 joerg Exp $

META_PACKAGE=	yes

.include "Makefile.common"

DISTNAME=	mecab-${MECAB_VERSION}
DISTFILES=	#empty

COMMENT=	Yet Another Part-of-Speech and Morphological Analyzer

DEPENDS+=	{mecab-ipadic>=2.7.0,mecab-jumandic>=5.1}:../../textproc/mecab-ipadic
DEPENDS+=	mecab-base>=${MECAB_VERSION}:../../textproc/mecab-base

.include "../../mk/bsd.pkg.mk"
