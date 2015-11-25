# $NetBSD: Makefile,v 1.8 2015/11/25 12:53:42 jperkin Exp $
#

.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-ipadic-2.7.0-20070610
PKGNAME=	mecab-ipadic-2.7.0.20070610
PKGREVISION=	1

COMMENT=	Japanese Morphological Dictionary for MeCab
#LICENSE=	# See ${WRKSRC}/COPYING

BUILD_DEPENDS+=	mecab-base-[0-9]*:../../textproc/mecab-base

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-charset=${MECAB_CHARSET:Q}

BUILD_DEFS+=		MECAB_CHARSET

CONFIGURE_ARGS+=	--with-mecab-config=${LOCALBASE}/bin/mecab-config

.include "../../mk/bsd.pkg.mk"
