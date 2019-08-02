# $NetBSD: Makefile,v 1.4 2019/08/02 14:04:31 jperkin Exp $

DISTNAME=	fstrm-0.5.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=farsightsec/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TYPE=	tag

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://github.com/farsightsec/fstrm/
COMMENT=	C implementation of the Frame Streams data transport protocol
LICENSE=	mit

USE_TOOLS+=	autoconf
USE_TOOLS+=	automake
USE_TOOLS+=	pkg-config
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c

BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0

LDFLAGS.SunOS+=	-lnsl

pre-configure:
	cd ${WRKSRC} && sh ./autogen.sh

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
