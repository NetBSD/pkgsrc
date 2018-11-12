# $NetBSD: Makefile,v 1.38 2018/11/12 03:52:30 ryoon Exp $
#

DISTNAME=		calcoo-1.3.18
PKGREVISION=		27
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=calcoo/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://calcoo.sourceforge.net/
COMMENT=		Scientific calculator

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
LDFLAGS+=		-lm	# direct link required by ld v2.22

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
