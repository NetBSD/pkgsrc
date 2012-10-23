# $NetBSD: Makefile,v 1.2 2012/10/23 17:18:44 asau Exp $
#

DISTNAME=	omniNotify-2.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=omninotify/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://omninotify.sourceforge.net/
COMMENT=	CORBA Notification Service
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/omniNotify
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

.include "../../net/omniORB/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
