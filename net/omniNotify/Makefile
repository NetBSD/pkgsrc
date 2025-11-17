# $NetBSD: Makefile,v 1.8 2025/11/17 11:01:15 wiz Exp $
#

DISTNAME=	omniNotify-2.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=omninotify/}

PATCH_SITES=		http://www.NetBSD.org/~dholland/patchkits/omniNotify/
PATCHFILES=		omniNotify-jumbo-patch-20151224.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://omninotify.sourceforge.net/
COMMENT=	CORBA Notification Service
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/omniNotify
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

post-extract:
	# avoid rebuilding file
	${TOUCH} ${WRKSRC}/mkattlib/AttNotificationDynSK.cc

.include "../../net/omniORB/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
