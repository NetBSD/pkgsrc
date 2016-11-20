# $NetBSD: Makefile,v 1.12 2016/11/20 21:03:39 wiz Exp $

DISTNAME=	Coherence-0.6.6.2
PKGNAME=	coherence-0.6.6.2
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://coherence.beebits.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/coherence-project/Coherence
COMMENT=	Media server framework

USE_LANGUAGES=	# none

DEPENDS+= ${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-twisted

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
