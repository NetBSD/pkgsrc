# $NetBSD: Makefile,v 1.15 2004/04/25 09:18:51 snj Exp $
#

DISTNAME=	kmess-1.1
PKGREVISION=	7
CATEGORIES=	chat kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kmess/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://kmess.sourceforge.net/
COMMENT=	MSN Messenger Client for KDE3

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes

.include "../../audio/arts/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
