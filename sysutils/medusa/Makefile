# $NetBSD: Makefile,v 1.6 2002/09/23 23:38:30 jlam Exp $
#

DISTNAME=		medusa-0.5.1
PKGREVISION=		1
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/medusa/}	\
			http://download.eazel.com/source/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.eazel.com/
COMMENT=		file system indexing engine

DEPENDS+=		psmisc-[0-9]*:../../sysutils/psmisc

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../sysutils/gnome-vfs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
