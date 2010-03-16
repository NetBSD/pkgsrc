# $NetBSD: dist.mk,v 1.8 2010/03/16 15:57:02 tnn Exp $
#
# used by devel/nspr/Makefile
# used by devel/nss/Makefile
# used by devel/xulrunner/Makefile
# used by www/firefox/Makefile

DISTNAME=	firefox-${FIREFOX_VER}.source
FIREFOX_VER=	3.6${MOZ_BRANCH_MINOR}
MOZ_BRANCH=	1.9.2
MOZ_BRANCH_MINOR=	.2
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

DISTINFO_FILE=	${.CURDIR}/../../devel/xulrunner/distinfo
PATCHDIR=	${.CURDIR}/../../devel/xulrunner/patches

WRKSRC=		${WRKDIR}/mozilla-${MOZ_BRANCH}

# snapshot overrides
DISTNAME=	f14062c981ba
MASTER_SITES=	http://hg.mozilla.org/releases/mozilla-1.9.2/archive/
WRKSRC=		${WRKDIR}/mozilla-1-9-2-f14062c981ba
