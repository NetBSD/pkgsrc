# $NetBSD: Makefile,v 1.7 2004/01/24 14:50:05 grant Exp $
#

DISTNAME=		aMule-1.2.4
PKGNAME=		${DISTNAME:S/aMule/amule/}
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=amule/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://amule.sourceforge.net/
COMMENT=		Another Emule P2P client

DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

CONFLICTS=		xmule-[0-9]*

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../www/curl/buildlink2.mk"
.include "../../x11/wxGTK/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
