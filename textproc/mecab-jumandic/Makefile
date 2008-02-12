# $NetBSD: Makefile,v 1.2 2008/02/12 14:18:39 obache Exp $
#

.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-jumandic-5.1-20070304
PKGNAME=	mecab-jumandic-5.1.20070304

COMMENT=	Japanese Morphological Dictionary for MeCab

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

UNLIMIT_RESOURCES=	datasize

.include "../../textproc/mecab-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
