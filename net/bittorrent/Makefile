# $NetBSD: Makefile,v 1.9 2003/08/28 15:02:28 recht Exp $
#

DISTNAME=	BitTorrent-3.2.1b
PKGNAME=	${DISTNAME:S/BitT/bitt/}
PKGREVISION=	2
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
