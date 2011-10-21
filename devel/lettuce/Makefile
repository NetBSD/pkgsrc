# $NetBSD: Makefile,v 1.1.1.1 2011/10/21 12:35:30 reed Exp $
#

DISTNAME=	lettuce-0.1.33
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/l/lettuce/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://lettuce.it/
COMMENT=	Behaviour-driven development test tool
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

# not ported yet
PYTHON_VERSIONS_INCOMPATIBLE=	31

.include "../../lang/python/egg.mk"

.include "../../mk/bsd.pkg.mk"
