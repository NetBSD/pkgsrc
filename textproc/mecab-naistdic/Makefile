# $NetBSD: Makefile,v 1.7 2023/06/06 12:42:25 riastradh Exp $
#

DISTNAME=	mecab-naist-jdic-0.6.3-20100801
PKGNAME=	${DISTNAME:S/naist-jdic/naistjdic/}
PKGREVISION=	1
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_OSDN:=naist-jdic/48487/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://osdn.jp/projects/naist-jdic/wiki/FrontPage
COMMENT=	Japanese Morphological Dictionary for MeCab
LICENSE=	modified-bsd

TOOL_DEPENDS+=	mecab-base-[0-9]*:../../textproc/mecab-base

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-charset=${MECAB_CHARSET:Q}

BUILD_DEFS+=		MECAB_CHARSET

UNLIMIT_RESOURCES=	datasize

CONFIGURE_ARGS+=	--with-mecab-config=${LOCALBASE}/bin/mecab-config

.include "../../mk/bsd.pkg.mk"
