# $NetBSD: Makefile,v 1.4 2008/04/10 16:43:58 obache Exp $
#

.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-ipadic-2.7.0-20070610
PKGNAME=	mecab-ipadic-2.7.0.20070610

COMMENT=	Japanese Morphological Dictionary for MeCab

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-charset=${MECAB_CHARSET:Q}

BUILD_DEFS+=		MECAB_CHARSET

.include "../../textproc/mecab-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
