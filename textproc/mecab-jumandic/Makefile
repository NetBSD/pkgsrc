# $NetBSD: Makefile,v 1.4 2010/05/16 00:25:26 obache Exp $
#

.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-jumandic-5.1-20070304
PKGNAME=	mecab-jumandic-5.1.20070304

COMMENT=	Japanese Morphological Dictionary for MeCab
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-charset=${MECAB_CHARSET:Q}

BUILD_DEFS+=		MECAB_CHARSET

UNLIMIT_RESOURCES=	datasize

.include "../../textproc/mecab-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
