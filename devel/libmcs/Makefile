# $NetBSD: Makefile,v 1.3 2008/11/10 11:39:48 wiz Exp $
#

DISTNAME=	libmcs-0.7.1
CATEGORIES=	devel
MASTER_SITES=	http://distfiles.atheme.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jfranz@bsdprojects.net
#HOMEPAGE=	http://sacredspiral.co.uk/~nenolod/mcs/
COMMENT=	BSD licensed configuration database system

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libmcs.pc.in

.include "../../devel/libmowgli/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
