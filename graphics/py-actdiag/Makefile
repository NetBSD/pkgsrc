# $NetBSD: Makefile,v 1.4 2012/03/21 14:36:47 obache Exp $
#

DISTNAME=	actdiag-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	http://pypi.python.org/packages/source/a/actdiag/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://blockdiag.com/actdiag/build/html/
COMMENT=	Simple activity-diagram image generator
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-blockdiag>=1.1.2:../../graphics/py-blockdiag

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/actdiag.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
