# $NetBSD: Makefile,v 1.9 2011/01/13 13:39:20 wiz Exp $
#

DISTNAME=		bubblemon-dockapp-1.46
PKGNAME=		${DISTNAME:S/-dockapp//}
PKGREVISION=		7
CATEGORIES=		sysutils
MASTER_SITES=		http://www.ne.jp/asahi/linux/timecop/software/

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ne.jp/asahi/linux/timecop/
COMMENT=		Small windowmaker dockapp with bubbles and a duck
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		gmake pkg-config

INSTALLATION_DIRS+=	bin

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
