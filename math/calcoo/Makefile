# $NetBSD: Makefile,v 1.17 2011/12/18 10:07:07 marino Exp $
#

DISTNAME=		calcoo-1.3.18
PKGREVISION=		7
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=calcoo/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://calcoo.sourceforge.net/
COMMENT=		Scientific calculator

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
LDFLAGS+=		-lm	# direct link required by ld v2.22

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
