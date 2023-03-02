# $NetBSD: Makefile,v 1.1 2023/03/02 03:44:39 charlotte Exp $

DISTNAME=	openjazz-20190106
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=AlisterT/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
COMMENT=	Open source reimplementation of the Jazz Jackrabbit games
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	gtar
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_TOOLS+=	automake autoconf autoreconf pkg-config

pre-configure:
	${RUN} cd ${WRKSRC} && autoreconf -fiv

.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/libxmp/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
