# $NetBSD: Makefile,v 1.13 2004/01/23 21:50:43 jmmv Exp $
#

DISTNAME=	kmess-1.1
PKGREVISION=	6
CATEGORIES=	chat kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kmess/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://kmess.sourceforge.net/
COMMENT=	MSN Messenger Client for KDE3

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes

.include "../../audio/arts/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
