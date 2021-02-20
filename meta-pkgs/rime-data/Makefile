# $NetBSD: Makefile,v 1.1 2021/02/20 20:58:57 ryoon Exp $
#

DISTNAME=	rime-data-0.0.1
CATEGORIES=	meta-pkgs inputmethod chinese
MASTER_SITES=	# empty

MAINTAINER=	ryoon@NetBSD.org
COMMENT=	Provides RIME inputmethod schema and data

DEPENDS+=	rime-prelude-[0-9]*:../../inputmethod/rime-prelude
DEPENDS+=	rime-bopomofo-[0-9]*:../../inputmethod/rime-bopomofo
DEPENDS+=	rime-cangjie-[0-9]*:../../inputmethod/rime-cangjie
DEPENDS+=	rime-terra-pinyin-[0-9]*:../../inputmethod/rime-terra-pinyin

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
