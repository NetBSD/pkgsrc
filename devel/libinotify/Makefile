# $NetBSD: Makefile,v 1.4 2015/03/12 14:54:14 tnn Exp $
#

DISTNAME=	libinotify-0.0
CATEGORIES=	devel
MASTER_SITES=	http://dmitrymatveev.co.uk/files/

MAINTAINER=	me@dmitrymatveev.co.uk
HOMEPAGE=	http://dmitrymatveev.co.uk/gsoc11
COMMENT=	Inotify emulation library for *BSDs
LICENSE=	mit

GNU_CONFIGURE=  YES
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf automake autoreconf

NOT_FOR_PLATFORM+=	SunOS-*-*

pre-configure:
	cd ${WRKSRC} && autoreconf -fvi

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
