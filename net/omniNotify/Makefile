# $NetBSD: Makefile,v 1.1.1.1 2010/09/02 15:20:36 drochner Exp $
#

DISTNAME=	omniNotify-2.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=omninotify/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://omninotify.sourceforge.net/
COMMENT=	CORBA Notification Service
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/omniNotify
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

.include "../../net/omniORB/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
