# $NetBSD: Makefile,v 1.1.1.1 2004/03/05 22:31:42 ben Exp $
#

DISTNAME=		libmodplug-0.7
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=modplug-xmms/}

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://modplug-xmms.sourceforge.net/
COMMENT=		Library for decoding mod-like music formats

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
