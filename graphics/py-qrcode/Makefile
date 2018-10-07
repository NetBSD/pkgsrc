# $NetBSD: Makefile,v 1.13 2018/10/07 08:55:13 adam Exp $

DISTNAME=	qrcode-6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=q/qrcode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/qrcode
COMMENT=	Python QR Code image generator
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	qrcode/console_scripts.py

SUBST_CLASSES+=			pkgmandir
SUBST_FILES.pkgmandir=		setup.py
SUBST_MESSAGE.pkgmandir=	Fixing PKGMANDIR path.
SUBST_SED.pkgmandir=		-e "s|share/man|${PKGMANDIR}|1"
SUBST_STAGE.pkgmandir=		pre-configure

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/qr \
		${DESTDIR}${PREFIX}/bin/qr-${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/qr.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/qr-${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
