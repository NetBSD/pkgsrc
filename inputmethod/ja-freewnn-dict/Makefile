# $NetBSD: Makefile,v 1.7 2010/02/15 14:00:01 joerg Exp $
#

PKGNAME=	ja-FreeWnn-dict-1.10
PKGREVISION=	1
CATEGORIES=	japanese inputmethod

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.freewnn.org/
COMMENT=	Japanese/Chinese/Korean input method (Japanese dictionary)

BUILD_DEPENDS+=	ja-FreeWnn-server-bin>=1.10nb1:../../inputmethod/ja-freewnn-server-bin

MAKE_JOBS_SAFE=	no

WNNDIR=		Wnn
WNN_TARGET=	DICT
WNN_LANG=	ja_JP

FILESDIR=	${.CURDIR}/../ja-freewnn-lib/files
DISTINFO_FILE=	${.CURDIR}/../ja-freewnn-lib/distinfo
PATCHDIR=	${.CURDIR}/../ja-freewnn-lib/patches

.include "../../mk/bsd.prefs.mk"

INSTALLATION_PREFIX=	${IMDICTDIR}

.include "../../inputmethod/ja-freewnn-lib/Makefile.common"
