# $NetBSD: Makefile,v 1.40 2004/10/03 00:18:14 tv Exp $
#

DISTNAME=		gcombust-0.1.54
PKGREVISION=		4
CATEGORIES=		x11 sysutils
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.abo.fi/~jmunsin/gcombust/
COMMENT=		Graphical frontend for CD mastering (mkisofs, cdrecord, ...)

DEPENDS+=		cdrecord>=1.10:../../sysutils/cdrecord
DEPENDS+=		cdlabelgen-[0-9]*:../../graphics/cdlabelgen
DEPENDS+=		gv-[0-9]*:../../print/gv

USE_BUILDLINK3=		YES
USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
