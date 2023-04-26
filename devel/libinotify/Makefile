# $NetBSD: Makefile,v 1.10 2023/04/26 16:03:30 wiz Exp $

DISTNAME=	libinotify
PKGNAME=	${DISTNAME}-0.0.${GITHUB_TAG}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libinotify-kqueue/}
GITHUB_PROJECT=	libinotify-kqueue
GITHUB_TAG=	20211018

MAINTAINER=	me@dmitrymatveev.co.uk
#HOMEPAGE=	http://dmitrymatveev.co.uk/gsoc11
COMMENT=	Inotify emulation library for *BSDs
LICENSE=	mit

GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf automake autoreconf

TEST_TARGET=	test

NOT_FOR_PLATFORM+=	SunOS-*-* Linux-*-*

pre-configure:
	cd ${WRKSRC} && autoreconf -fvi

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
