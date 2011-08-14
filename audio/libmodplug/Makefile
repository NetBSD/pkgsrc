# $NetBSD: Makefile,v 1.11.2.1 2011/08/14 11:17:36 tron Exp $
#

DISTNAME=		libmodplug-0.8.8.4
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=modplug-xmms/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://modplug-xmms.sourceforge.net/
COMMENT=		Library for decoding mod-like music formats
LICENSE=		public-domain

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	libmodplug.pc.in

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
