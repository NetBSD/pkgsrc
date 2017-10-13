# $NetBSD: Makefile,v 1.16 2017/10/13 16:00:59 adam Exp $

DISTNAME=	libmodplug-0.8.9.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=modplug-xmms/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://modplug-xmms.sourceforge.net/
COMMENT=	Library for decoding mod-like music formats
LICENSE=	public-domain

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	libmodplug.pc.in

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
