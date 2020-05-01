# $NetBSD: Makefile,v 1.12 2020/05/01 00:14:17 joerg Exp $
#

DISTNAME=	embryo-1.7.10
CATEGORIES=	lang
MASTER_SITES=	https://download.enlightenment.org/att/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://enlightenment.org/
COMMENT=	Embeddable Scripting Language

# some potions of the code have a special license - but it's free, too
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	embryo.pc.in

.include "../../devel/eina/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
