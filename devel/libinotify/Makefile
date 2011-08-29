# $NetBSD: Makefile,v 1.1.1.1 2011/08/29 09:44:01 wiz Exp $
#

DISTNAME=	libinotify-0.0
CATEGORIES=	devel
MASTER_SITES=	http://dmitrymatveev.co.uk/files/

MAINTAINER=	me@dmitrymatveev.co.uk
HOMEPAGE=	http://dmitrymatveev.co.uk/gsoc11
COMMENT=	Inotify emulation library for *BSDs
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=  YES
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf automake autoreconf

pre-configure:
	cd ${WRKSRC} && autoreconf -fvi

.include "../../mk/bsd.pkg.mk"
