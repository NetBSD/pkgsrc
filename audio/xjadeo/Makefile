# $NetBSD: Makefile,v 1.3 2016/08/17 00:06:41 ryoon Exp $

DISTNAME=	xjadeo-0.8.5
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=x42/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xjadeo.sourceforge.net/
COMMENT=	X JAck viDEo mOnitor
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

USE_TOOLS+=	automake aclocal autoheader autoconf pkg-config

GNU_CONFIGURE=	yes

pre-configure:
	${RUN} cd ${WRKSRC} && ./autogen.sh

.include "../../audio/jack/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
