# $NetBSD: Makefile,v 1.11 2023/09/11 07:52:43 triaxx Exp $

DISTNAME=	libinotify
PKGNAME=	${DISTNAME}-0.0.${GITHUB_TAG}
PKGREVISON=	1
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
USE_LANGUAGES=	c c++17
USE_TOOLS+=	autoconf automake autoreconf

# Avoid error due to use of ATOMIC_VAR_INIT.
CFLAGS+=	-Wno-deprecated-pragma

TEST_TARGET=	test

NOT_FOR_PLATFORM+=	SunOS-*-* Linux-*-*

pre-configure:
	cd ${WRKSRC} && autoreconf -fvi

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
