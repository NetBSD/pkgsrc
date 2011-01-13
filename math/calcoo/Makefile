# $NetBSD: Makefile,v 1.14 2011/01/13 13:38:39 wiz Exp $
#

DISTNAME=		calcoo-1.3.18
PKGREVISION=		5
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
