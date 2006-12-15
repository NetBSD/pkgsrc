# $NetBSD: Makefile,v 1.7 2006/12/15 14:34:19 wiz Exp $
#

DISTNAME=		libmodplug-0.7
PKGREVISION=		1
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
