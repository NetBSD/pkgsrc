# $NetBSD: Makefile,v 1.2 2002/08/12 09:44:15 agc Exp $
#

PKGNAME=	ja-FreeWnn-server-bin-1.10
PKGREVISION=	1
CATEGORIES=	japanese inputmethod

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.freewnn.org/
COMMENT=	Japanese/Chinese/Korean input method (Japanese server binary)

WNNDIR=		Wnn
WNN_TARGET=	SERVER
WNN_LANG=	ja_JP

FILESDIR=	${.CURDIR}/../ja-freewnn-lib/files
DISTINFO_FILE=	${.CURDIR}/../ja-freewnn-lib/distinfo
PATCHDIR=	${.CURDIR}/../ja-freewnn-lib/patches

.include "../../mk/bsd.prefs.mk"

FREEWNN_USER?=	wnn
FREEWNN_GROUP?=	jserver
BUILD_DEFS+=	FREEWNN_USER FREEWNN_GROUP

PKG_GROUPS=	${FREEWNN_GROUP}
PKG_USERS=	${FREEWNN_USER}:${FREEWNN_GROUP}::Freewnn\\ user

.include "../../mk/bsd.pkg.install.mk"
.include "../ja-freewnn-lib/buildlink.mk"
.include "../ja-freewnn-lib/Makefile.common"
