# $NetBSD: Makefile,v 1.5 2012/02/29 09:10:06 obache Exp $
#

.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-jumandic-5.1-20070304
PKGNAME=	mecab-jumandic-5.1.20070304
PKGREVISION=	1

COMMENT=	Japanese Morphological Dictionary for MeCab
LICENSE=	modified-bsd

BUILD_DEPENDS+=	mecab-base-[0-9]*:../../textproc/mecab-base

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-charset=${MECAB_CHARSET:Q}

BUILD_DEFS+=		MECAB_CHARSET

UNLIMIT_RESOURCES=	datasize

FIND_PREFIX:=	MECABDIR=mecab-base
.include "../../mk/find-prefix.mk"
CONFIGURE_ARGS+=	--with-mecab-config=${MECABDIR}/bin/mecab-config

.include "../../mk/bsd.pkg.mk"
