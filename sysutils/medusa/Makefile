# $NetBSD: Makefile,v 1.16 2004/10/03 00:18:16 tv Exp $
#

DISTNAME=		medusa-0.5.1
PKGREVISION=		6
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/medusa/0.5/}	\
			http://download.eazel.com/source/

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.eazel.com/
COMMENT=		File system indexing engine

DEPENDS+=		psmisc-[0-9]*:../../sysutils/psmisc

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
