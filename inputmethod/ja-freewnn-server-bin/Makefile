# $NetBSD: Makefile,v 1.1.1.1 2002/06/10 09:13:31 sakamoto Exp $
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

.include "../ja-freewnn-lib/buildlink.mk"
.include "../ja-freewnn-lib/Makefile.common"
