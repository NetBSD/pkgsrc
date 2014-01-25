# $NetBSD: Makefile,v 1.42 2014/01/25 10:30:16 wiz Exp $

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
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-gtk2

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
