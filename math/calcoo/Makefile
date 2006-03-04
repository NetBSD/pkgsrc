# $NetBSD: Makefile,v 1.6 2006/03/04 21:30:03 jlam Exp $
#

DISTNAME=		calcoo-1.3.16
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=calcoo/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://calcoo.sourceforge.net/
COMMENT=		Scientific calculator

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
