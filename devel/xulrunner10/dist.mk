# $NetBSD: dist.mk,v 1.11 2013/01/10 12:01:02 is Exp $
#
# used by devel/xulrunner10/Makefile
# used by www/firefox10/Makefile

DISTNAME=	firefox-${FIREFOX_VER}esr.source
FIREFOX_VER=	${MOZ_BRANCH}${MOZ_BRANCH_MINOR}
MOZ_BRANCH=	10.0
MOZ_BRANCH_MINOR=	.12
MASTER_SITES=	${MASTER_SITE_MOZILLA_ESR:=firefox/releases/${FIREFOX_VER}esr/source/}
EXTRACT_SUFX=	.tar.bz2

DISTINFO_FILE=	${.CURDIR}/../../devel/xulrunner10/distinfo
PATCHDIR=	${.CURDIR}/../../devel/xulrunner10/patches

WRKSRC=		${WRKDIR}/mozilla-esr10
