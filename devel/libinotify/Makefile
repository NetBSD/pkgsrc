# $NetBSD: Makefile,v 1.7 2017/08/16 20:45:35 wiz Exp $
#

DISTNAME=	libinotify-0.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=dmatveev/}
GITHUB_PROJECT=	libinotify-kqueue
GITHUB_TAG=	b2873cf8a94b0574819075a003e33c0405f1b690

MAINTAINER=	me@dmitrymatveev.co.uk
#HOMEPAGE=	http://dmitrymatveev.co.uk/gsoc11
COMMENT=	Inotify emulation library for *BSDs
LICENSE=	mit

GNU_CONFIGURE=  YES
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf automake autoreconf

TEST_TARGET=	test

NOT_FOR_PLATFORM+=	SunOS-*-* Linux-*-*

pre-configure:
	cd ${WRKSRC} && autoreconf -fvi

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
