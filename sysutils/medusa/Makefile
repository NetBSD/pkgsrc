# $NetBSD: Makefile,v 1.4 2002/01/03 14:49:22 wiz Exp $
#

DISTNAME=		medusa-0.5.1
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/medusa/}	\
			http://download.eazel.com/source/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.eazel.com/
COMMENT=		file system indexing engine

DEPENDS+=		psmisc-[0-9]*:../../sysutils/psmisc

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_BUILDLINK_ONLY=	YES

.include "../../sysutils/gnome-vfs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
