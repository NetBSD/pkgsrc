# $NetBSD: Makefile,v 1.1.1.1 2004/12/04 03:57:44 taya Exp $

DISTNAME=	anthy-5900
CATEGORIES=	inputmethod
MASTER_SITES=	http://downloads.sourceforge.jp/anthy/12071/
DISTFILES=	${DISTNAME}.tar.gz
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	taya@NetBSD.org
HOMEPAGE=	http://anthy.sourceforge.jp/
COMMENT=	Kana Kanji conversion system

USE_LIBTOOL=		yes
USE_LANGUAGES=		c
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

EMACS_USE_LEIM= # defined

# Global and legacy options
.if defined(USE_2CH_DICT) && ${USE_2CH_DICT} == "yes"
PKG_DEFAULT_OPTIONS+=	2ch_dict
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.anthy
PKG_SUPPORTED_OPTIONS=	2ch_dict

.include	"../../mk/bsd.options.mk"

###
### 2ch dictionary support
###
.if !empty(PKG_OPTIONS:M2ch_dict)
DISTFILES+=	2ch.t
SITES_2ch.t+=	http://omaemona.sourceforge.net/packages/Zisyo/

post-extract:
	${CP} ${DISTDIR}/2ch.t ${WRKSRC}/mkanthydic
.endif

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
