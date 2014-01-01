# $NetBSD: Makefile,v 1.6 2014/01/01 11:52:10 wiz Exp $
#

DISTNAME=	bodr-9
PKGREVISION=	4
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bodr/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://blueobelisk.org/
COMMENT=	Blue Obelisk Data Repository
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake perl
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	bodr.pc.in

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
