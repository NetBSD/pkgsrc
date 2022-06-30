# $NetBSD: Makefile,v 1.18 2022/06/30 11:18:31 nia Exp $

DISTNAME=	tegaki-pygtk-0.3.1
PKGREVISION=	6
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Base user interface library for the Tegaki project
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-python>=0.2:../../inputmethod/tegaki-python
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.10:../../x11/py-gtk2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27 # py-gtk2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
