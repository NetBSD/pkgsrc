# $NetBSD: Makefile,v 1.7 2016/06/09 05:54:32 wiz Exp $

DISTNAME=	qrcode-5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PYPI:=q/qrcode/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/qrcode
COMMENT=	Python QR Code image generator
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

REPLACE_PYTHON+=		qrcode/console_scripts.py
SUBST_CLASSES+=			pkgmandir
SUBST_FILES.pkgmandir=		setup.py
SUBST_MESSAGE.pkgmandir=	Fixing PKGMANDIR path.
SUBST_SED.pkgmandir=		-e "s|share/man|${PKGMANDIR}|1"
SUBST_STAGE.pkgmandir=		post-patch

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/qr \
		${DESTDIR}${PREFIX}/bin/qr${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/qr.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/qr${PYVERSSUFFIX}.1

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
