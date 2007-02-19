# $NetBSD: Makefile,v 1.27 2007/02/19 17:49:03 joerg Exp $
#

DISTNAME=		medusa-0.5.1
PKGREVISION=		10
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/medusa/0.5/}	\
			http://download.eazel.com/source/

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.eazel.com/
COMMENT=		File system indexing engine

DEPENDS+=		psmisc-[0-9]*:../../sysutils/psmisc

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
