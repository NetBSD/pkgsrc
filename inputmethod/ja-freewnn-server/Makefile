# $NetBSD: Makefile,v 1.1.1.1 2002/05/31 13:01:28 seb Exp $
#

PKGNAME=	ja-FreeWnn-server-1.10
CATEGORIES=	japanese inputmethod
DEPENDS+=	ja-FreeWnn-lib-1.10:../../inputmethod/ja-freewnn-lib

COMMENT=	Japanese/Chinese/Korean input method (Japanese server)

WNNDIR=		Wnn
WNN_TARGET=	SERVER
WNN_LANG=	ja_JP

FILESDIR=	${.CURDIR}/../../inputmethod/ja-freewnn-lib/files
PATCHDIR=	${.CURDIR}/../../inputmethod/ja-freewnn-lib/patches

.include "../../inputmethod/ja-freewnn-lib/Makefile.common"
