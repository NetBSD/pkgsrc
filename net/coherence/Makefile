# $NetBSD: Makefile,v 1.18 2019/04/26 13:14:07 maya Exp $

DISTNAME=	Coherence-0.6.6.2
PKGNAME=	coherence-0.6.6.2
PKGREVISION=	3
CATEGORIES=	net
#MASTER_SITES=	http://coherence.beebits.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/coherence-project/Coherence
COMMENT=	Media server framework

USE_LANGUAGES=	# none

DEPENDS+= ${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # as of 0.6.6.2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
