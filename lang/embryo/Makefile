# $NetBSD: Makefile,v 1.13 2022/11/09 13:14:14 joerg Exp $
#

DISTNAME=	embryo-1.7.10
CATEGORIES=	lang
MASTER_SITES=	https://download.enlightenment.org/att/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
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
