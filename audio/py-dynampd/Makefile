# $NetBSD: Makefile,v 1.3 2012/10/03 23:40:37 cheusov Exp $
#

DISTNAME=	dynampd
VERSION=	1.1.0
PKGNAME=	${PYPKGPREFIX}-dynampd-${VERSION}
CATEGORIES=	audio
MASTER_SITES=	http://dynampd.ubitux.fr/
EXTRACT_SUFX=	.py

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dynampd.ubitux.fr/
COMMENT=	Dynamic playlist generator for MPD
#LICENSE=	wtfpl

DEPENDS+=	${PYPKGPREFIX}-mpd-[0-9]*:../../audio/py-mpd
DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson

DIST_SUBDIR=		dynampd-${VERSION}
WRKSRC=			${WRKDIR}
USE_LANGUAGES=		# none
INSTALLATION_DIRS=	bin
REPLACE_PYTHON=		dynampd.py

PYTHON_SELF_CONFLICT=	yes

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dynampd.py ${DESTDIR}${PREFIX}/bin/dynampd

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
