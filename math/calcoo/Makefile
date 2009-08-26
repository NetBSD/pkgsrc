# $NetBSD: Makefile,v 1.10 2009/08/26 19:57:58 sno Exp $
#

DISTNAME=		calcoo-1.3.18
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=calcoo/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://calcoo.sourceforge.net/
COMMENT=		Scientific calculator

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
