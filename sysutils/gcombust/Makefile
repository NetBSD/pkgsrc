# $NetBSD: Makefile,v 1.47 2012/10/23 19:51:03 asau Exp $
#

DISTNAME=		gcombust-0.1.54
PKGREVISION=		7
CATEGORIES=		x11 sysutils
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.abo.fi/~jmunsin/gcombust/
COMMENT=		Graphical frontend for CD mastering (mkisofs, cdrecord, ...)

DEPENDS+=		cdrtools>=1.10:../../sysutils/cdrtools
DEPENDS+=		cdlabelgen-[0-9]*:../../graphics/cdlabelgen
DEPENDS+=		gv-[0-9]*:../../print/gv

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
