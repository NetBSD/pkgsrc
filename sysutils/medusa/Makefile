# $NetBSD: Makefile,v 1.3 2001/09/27 23:18:43 jlam Exp $
#

DISTNAME=		medusa-0.5.1
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/medusa/}	\
			http://download.eazel.com/source/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.eazel.com/
COMMENT=		file system indexing engine

DEPENDS+=		psmisc-[0-9]*:../../sysutils/psmisc
DEPENDS+=		gnome-vfs>=1.0.1:../../sysutils/gnome-vfs

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CPPFLAGS+=		-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
