# $NetBSD: Makefile,v 1.13 2004/01/10 14:25:42 recht Exp $
#

DISTNAME=	BitTorrent-3.3
PKGNAME=	${DISTNAME:S/BitT/bitt/}
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://bitconjurer.org/BitTorrent/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://bitconjurer.org/BitTorrent/
COMMENT=	File sharing tool

PYDISTUTILSPKG=	YES
USE_BUILDLINK2=	YES

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-wxWindows/buildlink2.mk"
.include "../../devel/py-cursespanel/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
