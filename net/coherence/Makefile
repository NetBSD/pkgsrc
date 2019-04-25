# $NetBSD: Makefile,v 1.17 2019/04/25 07:33:10 maya Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.6.6.2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
