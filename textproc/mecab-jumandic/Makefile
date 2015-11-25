# $NetBSD: Makefile,v 1.7 2015/11/25 12:53:42 jperkin Exp $
#

.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-jumandic-5.1-20070304
PKGNAME=	mecab-jumandic-5.1.20070304
PKGREVISION=	1

COMMENT=	Japanese Morphological Dictionary for MeCab
LICENSE=	modified-bsd

BUILD_DEPENDS+=	mecab-base-[0-9]*:../../textproc/mecab-base

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-charset=${MECAB_CHARSET:Q}

BUILD_DEFS+=		MECAB_CHARSET

UNLIMIT_RESOURCES=	datasize

CONFIGURE_ARGS+=	--with-mecab-config=${LOCALBASE}/bin/mecab-config

.include "../../mk/bsd.pkg.mk"
