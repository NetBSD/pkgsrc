# $NetBSD: Makefile,v 1.34 2003/05/05 16:50:27 jmmv Exp $
#

DISTNAME=		gcombust-0.1.54
PKGREVISION=		1
CATEGORIES=		x11 sysutils
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.abo.fi/~jmunsin/gcombust/
COMMENT=		Graphical frontend for CD mastering (mkisofs, cdrecord, ...)

DEPENDS+=		cdrecord>=1.10:../../sysutils/cdrecord
DEPENDS+=		cdlabelgen-[0-9]*:../../graphics/cdlabelgen
DEPENDS+=		gnome1-dirs>=1.0:../../misc/gnome1-dirs
DEPENDS+=		gv-[0-9]*:../../print/gv

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
