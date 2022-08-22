# $NetBSD: Makefile,v 1.2 2022/08/22 14:22:30 leot Exp $

DISTNAME=	zimg-3.0.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=sekrit-twc/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sekrit-twc/zimg
COMMENT=	"z" image processing library
LICENSE=	public-domain # "WTFPL" license: https://github.com/sekrit-twc/zimg/blob/master/COPYING

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	autoreconf autoconf automake

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
