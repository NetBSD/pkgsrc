# $NetBSD: Makefile,v 1.2 2008/07/14 12:56:02 joerg Exp $
#

DISTNAME=	mcs-0.4.1
PKGNAME=	lib${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://sacredspiral.co.uk/~nenolod/mcs/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://sacredspiral.co.uk/~nenolod/mcs/
COMMENT=	BSD licensed configuration database system

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libmcs.pc.in

.include "../../mk/bsd.pkg.mk"
