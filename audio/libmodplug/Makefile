# $NetBSD: Makefile,v 1.10 2009/05/02 19:26:58 tnn Exp $
#

DISTNAME=		libmodplug-0.8.7
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=modplug-xmms/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://modplug-xmms.sourceforge.net/
COMMENT=		Library for decoding mod-like music formats

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
