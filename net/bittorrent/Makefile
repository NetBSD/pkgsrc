# $NetBSD: Makefile,v 1.5 2003/06/04 19:35:19 drochner Exp $
#

DISTNAME=	BitTorrent-3.2.1b
PKGNAME=	${DISTNAME:S/BitT/bitt/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://bitconjurer.org/BitTorrent/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://bitconjurer.org/BitTorrent/
COMMENT=	file sharing tool

PYDISTUTILSPKG=	YES
USE_BUILDLINK2=	YES
PYTHON_VERSION_REQD= 22pth

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-wxWindows/buildlink2.mk"
.include "../../devel/py-cursespanel/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
