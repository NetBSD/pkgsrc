# $NetBSD: Makefile,v 1.4 2012/03/21 14:32:13 obache Exp $
#

DISTNAME=	seqdiag-0.7.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	http://pypi.python.org/packages/source/s/seqdiag/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://blockdiag.com/seqdiag/build/html/
COMMENT=	Simple sequence-diagram image generator
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-blockdiag>=1.1.2:../../graphics/py-blockdiag

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/seqdiag.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
