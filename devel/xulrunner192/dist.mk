# $NetBSD: dist.mk,v 1.5 2011/12/19 06:26:55 obache Exp $
#
# used by devel/xulrunner192/Makefile
# used by www/firefox36/Makefile

DISTNAME=	firefox-${FIREFOX_VER}.source
FIREFOX_VER=	3.6${MOZ_BRANCH_MINOR}
MOZ_BRANCH=	1.9.2
MOZ_BRANCH_MINOR=	.24
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

DISTINFO_FILE=	${.CURDIR}/../../devel/xulrunner192/distinfo
PATCHDIR=	${.CURDIR}/../../devel/xulrunner192/patches

WRKSRC=		${WRKDIR}/mozilla-${MOZ_BRANCH}
