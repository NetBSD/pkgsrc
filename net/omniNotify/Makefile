# $NetBSD: Makefile,v 1.9 2026/08/03 13:12:30 wiz Exp $

DISTNAME=	omniNotify-2.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=omninotify/}

PATCH_SITES=		http://www.NetBSD.org/~dholland/patchkits/omniNotify/
PATCHFILES=		omniNotify-jumbo-patch-20151224.gz

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
