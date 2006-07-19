# $NetBSD: Makefile,v 1.26 2006/07/19 19:14:39 jlam Exp $
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
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
