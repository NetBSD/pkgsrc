# $NetBSD: Makefile,v 1.15 2014/10/09 14:05:56 wiz Exp $

DISTNAME=		libmodplug-0.8.8.5
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=modplug-xmms/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://modplug-xmms.sourceforge.net/
COMMENT=		Library for decoding mod-like music formats
LICENSE=		public-domain

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	libmodplug.pc.in

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
