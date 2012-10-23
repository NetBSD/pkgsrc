# $NetBSD: Makefile,v 1.41 2012/10/23 17:18:42 asau Exp $
#

DISTNAME=	nicotine-1.0.8
PKGREVISION=	16
CATEGORIES=	net audio x11
MASTER_SITES=	http://nicotine.thegraveyard.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nicotine.thegraveyard.org/
COMMENT=	Client for soulseek, a peer-to-peer network for music
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-gtk2>=1.99.16:../../x11/py-gtk2

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# empty

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
