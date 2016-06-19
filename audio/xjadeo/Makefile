# $NetBSD: Makefile,v 1.1 2016/06/19 09:16:15 kamil Exp $

DISTNAME=	xjadeo-0.8.5
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

.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
