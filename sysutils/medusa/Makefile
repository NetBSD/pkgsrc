# $NetBSD: Makefile,v 1.15 2004/04/12 04:48:39 snj Exp $
#

DISTNAME=		medusa-0.5.1
PKGREVISION=		5
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
