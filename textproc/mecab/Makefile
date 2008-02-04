# $NetBSD: Makefile,v 1.3 2008/02/04 04:58:52 obache Exp $

.include "Makefile.common"

DISTNAME=	mecab-${MECAB_VERSION}
DISTFILES=	#empty

COMMENT=	Yet Another Part-of-Speech and Morphological Analyzer

DEPENDS+=	{mecab-ipadic>=2.7.0,mecab-jumandic>=5.1}:../../textproc/mecab-ipadic
DEPENDS+=	mecab-base>=${MECAB_VERSION}:../../textproc/mecab-base

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
