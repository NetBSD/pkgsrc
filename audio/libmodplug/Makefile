# $NetBSD: Makefile,v 1.8 2006/12/19 20:08:22 wiz Exp $
#

DISTNAME=		libmodplug-0.8.4
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=modplug-xmms/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://modplug-xmms.sourceforge.net/
COMMENT=		Library for decoding mod-like music formats

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
