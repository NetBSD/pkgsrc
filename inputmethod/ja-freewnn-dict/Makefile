# $NetBSD: Makefile,v 1.3 2004/12/12 04:19:06 grant Exp $
#

PKGNAME=	ja-FreeWnn-dict-1.10
PKGREVISION=	1
CATEGORIES=	japanese inputmethod

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.freewnn.org/
COMMENT=	Japanese/Chinese/Korean input method (Japanese dictionary)

BUILD_DEPENDS+=	ja-FreeWnn-server-bin>=1.10nb1:../ja-freewnn-server-bin

WNNDIR=		Wnn
WNN_TARGET=	DICT
WNN_LANG=	ja_JP

FILESDIR=	${.CURDIR}/../ja-freewnn-lib/files
DISTINFO_FILE=	${.CURDIR}/../ja-freewnn-lib/distinfo
PATCHDIR=	${.CURDIR}/../ja-freewnn-lib/patches

.include "../../mk/bsd.prefs.mk"

NO_MTREE=		YES
INSTALLATION_PREFIX=	${IMDICTDIR}

.include "../ja-freewnn-lib/Makefile.common"
