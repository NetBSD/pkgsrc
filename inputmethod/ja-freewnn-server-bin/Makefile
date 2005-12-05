# $NetBSD: Makefile,v 1.12 2005/12/05 20:50:23 rillig Exp $
#

PKGNAME=	ja-FreeWnn-server-bin-1.10
PKGREVISION=	4
CATEGORIES=	japanese inputmethod

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.freewnn.org/
COMMENT=	Japanese/Chinese/Korean input method (Japanese server binary)

WNNDIR=		Wnn
WNN_TARGET=	SERVER
WNN_LANG=	ja_JP

FILESDIR=	${.CURDIR}/../ja-freewnn-lib/files
DISTINFO_FILE=	${.CURDIR}/../ja-freewnn-lib/distinfo
PATCHDIR=	${.CURDIR}/../ja-freewnn-lib/patches

USE_PKGINSTALL=	yes

RCD_SCRIPTS=	ja_freewnn

.include "../../mk/bsd.prefs.mk"

FREEWNN_USER?=	wnn
FREEWNN_GROUP?=	jserver
BUILD_DEFS+=	FREEWNN_USER FREEWNN_GROUP

PKG_GROUPS=	${FREEWNN_GROUP}
PKG_USERS=	${FREEWNN_USER}:${FREEWNN_GROUP}::Freewnn\ user

.include "../../inputmethod/ja-freewnn-lib/buildlink3.mk"
.include "../../inputmethod/ja-freewnn-lib/Makefile.common"
