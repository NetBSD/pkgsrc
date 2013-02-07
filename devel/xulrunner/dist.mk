# $NetBSD: dist.mk,v 1.42 2013/02/07 20:32:42 ryoon Exp $
#
# used by devel/xulrunner/Makefile
# used by www/firefox/Makefile

DISTNAME=	firefox-${FIREFOX_VER}.source
FIREFOX_VER=	${MOZ_BRANCH}${MOZ_BRANCH_MINOR}
MOZ_BRANCH=	18.0
MOZ_BRANCH_MINOR=	.2
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/source/} \
		${MASTER_SITE_MOZILLA_ALL:=firefox/releases/${FIREFOX_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

DISTINFO_FILE=	${.CURDIR}/../../devel/xulrunner/distinfo
PATCHDIR=	${.CURDIR}/../../devel/xulrunner/patches

WRKSRC=		${WRKDIR}/mozilla-release
