# $NetBSD: Makefile,v 1.2 2008/01/05 23:24:46 heinz Exp $
#

DISTNAME=		libxml++-1.0.5
PKGNAME=		libxml++1-1.0.5
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libxml++/1.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://libxmlplusplus.sourceforge.net/
COMMENT=		C++ wrapper for the libxml XML parser library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libxml++-1.0.pc.in

CONFLICTS+=		libxml++-1.*

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
