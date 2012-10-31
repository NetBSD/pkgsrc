# $NetBSD: Makefile,v 1.21 2012/10/31 11:19:43 asau Exp $
#

DISTNAME=		rudiments-0.34
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rudiments/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://rudiments.sourceforge.net/
COMMENT=		C++ class library for client/server/daemon applications
LICENSE=		gnu-lgpl-v2

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
PLIST_VARS+=		shm

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD"
PLIST.shm=		yes
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
