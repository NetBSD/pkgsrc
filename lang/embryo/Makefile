# $NetBSD: Makefile,v 1.9 2012/10/02 20:11:38 asau Exp $
#

DISTNAME=	embryo-1.1.0
CATEGORIES=	lang
MASTER_SITES=	http://download.enlightenment.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Embeddable Scripting Language

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	embryo.pc.in

.include "../../devel/eina/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
