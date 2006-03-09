# $NetBSD: Makefile,v 1.5 2006/03/09 21:04:40 jlam Exp $
#

DISTNAME=		libmodplug-0.7
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=modplug-xmms/}

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://modplug-xmms.sourceforge.net/
COMMENT=		Library for decoding mod-like music formats

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c++

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
