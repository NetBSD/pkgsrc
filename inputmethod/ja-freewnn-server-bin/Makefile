# $NetBSD: Makefile,v 1.7 2004/04/18 23:52:05 wiz Exp $
#

PKGNAME=	ja-FreeWnn-server-bin-1.10
PKGREVISION=	2
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

USE_BUILDLINK3=	yes
USE_PKGINSTALL=	yes

.include "../../mk/bsd.prefs.mk"

FREEWNN_USER?=	wnn
FREEWNN_GROUP?=	jserver
BUILD_DEFS+=	FREEWNN_USER FREEWNN_GROUP

PKG_GROUPS=	${FREEWNN_GROUP}
PKG_USERS=	${FREEWNN_USER}:${FREEWNN_GROUP}::Freewnn\\ user

.include "../ja-freewnn-lib/buildlink3.mk"
.include "../ja-freewnn-lib/Makefile.common"
