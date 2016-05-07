# $NetBSD: Makefile,v 1.5.28.1 2016/05/07 18:52:25 bsiegert Exp $
#

DISTNAME=	libmcs-0.7.1
CATEGORIES=	devel
#MASTER_SITES=	http://distfiles.atheme.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jfranz@bsdprojects.net
#HOMEPAGE=	http://sacredspiral.co.uk/~nenolod/mcs/
COMMENT=	BSD licensed configuration database system
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libmcs.pc.in

.include "../../devel/libmowgli/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
