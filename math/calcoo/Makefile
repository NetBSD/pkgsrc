# $NetBSD: Makefile,v 1.60 2026/01/27 08:40:04 wiz Exp $
#

DISTNAME=		calcoo-1.3.18
PKGREVISION=		46
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=calcoo/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://calcoo.sourceforge.net/
COMMENT=		Scientific calculator

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
LDFLAGS+=		-lm	# direct link required by ld v2.22

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
