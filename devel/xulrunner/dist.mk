# $NetBSD: dist.mk,v 1.1 2009/11/06 15:44:34 tnn Exp $
#

DISTNAME=	firefox-${FIREFOX_VER}.source
FIREFOX_VER=	3.5.5
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

DISTINFO_FILE=	${.CURDIR}/../../devel/xulrunner/distinfo
PATCHDIR=	${.CURDIR}/../../devel/xulrunner/patches

WRKSRC=		${WRKDIR}/mozilla-1.9.1
