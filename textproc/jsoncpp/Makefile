# $NetBSD: Makefile,v 1.1 2014/04/18 22:26:08 wiz Exp $

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
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 0.6.0rc2nb20140217

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
