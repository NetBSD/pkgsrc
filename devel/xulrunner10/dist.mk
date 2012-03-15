# $NetBSD: dist.mk,v 1.1.1.1 2012/03/15 08:58:26 ryoon Exp $
#
# used by devel/xulrunner10/Makefile
# used by www/firefox10/Makefile

DISTNAME=	firefox-${FIREFOX_VER}esr.source
FIREFOX_VER=	${MOZ_BRANCH}${MOZ_BRANCH_MINOR}
MOZ_BRANCH=	10.0
MOZ_BRANCH_MINOR=	.3
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

DISTINFO_FILE=	${.CURDIR}/../../devel/xulrunner10/distinfo
PATCHDIR=	${.CURDIR}/../../devel/xulrunner10/patches

WRKSRC=		${WRKDIR}/mozilla-esr10
