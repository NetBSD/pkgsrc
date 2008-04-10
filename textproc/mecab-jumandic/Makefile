# $NetBSD: Makefile,v 1.3 2008/04/10 16:43:58 obache Exp $
#

.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-jumandic-5.1-20070304
PKGNAME=	mecab-jumandic-5.1.20070304

COMMENT=	Japanese Morphological Dictionary for MeCab

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-charset=${MECAB_CHARSET:Q}

BUILD_DEFS+=		MECAB_CHARSET

UNLIMIT_RESOURCES=	datasize

.include "../../textproc/mecab-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
