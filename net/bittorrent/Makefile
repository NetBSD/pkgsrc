# $NetBSD: Makefile,v 1.1.1.1 2003/05/09 18:07:01 drochner Exp $
#

DISTNAME=	BitTorrent-3.2.1b
CATEGORIES=	net
MASTER_SITES=	http://bitconjurer.org/BitTorrent/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://bitconjurer.org/BitTorrent/
COMMENT=	file sharing tool

PYDISTUTILSPKG=	yes
USE_BUILDLINK2=	YES
PYTHON_VERSION_REQD= 22pth

.include "../../x11/py-wxWindows/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
