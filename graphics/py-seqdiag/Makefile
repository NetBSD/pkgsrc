# $NetBSD: Makefile,v 1.9 2013/12/06 11:30:53 obache Exp $
#

DISTNAME=	seqdiag-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	http://pypi.python.org/packages/source/s/seqdiag/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://blockdiag.com/seqdiag/build/html/
COMMENT=	Simple sequence-diagram image generator
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-blockdiag>=1.3.0:../../graphics/py-blockdiag

PYTHON_SELF_CONFLICT=		yes
PYTHON_VERSIONS_INCLUDE_3X=	yes

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/seqdiag.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
