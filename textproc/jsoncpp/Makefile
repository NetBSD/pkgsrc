# $NetBSD: Makefile,v 1.3 2015/12/05 21:26:01 adam Exp $

DISTNAME=	jsoncpp-src-0.6.0rc2svn276
PKGNAME=	${DISTNAME:C/-src//}
CATEGORIES=	textproc
MASTER_SITES=	# manually extracted from SVN

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jsoncpp.sourceforge.net/
COMMENT=	JSON reader and writer in C++
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
WRKSRC=		${WRKDIR}/jsoncpp

# for tests
PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.6.0rc2nb20140217

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
