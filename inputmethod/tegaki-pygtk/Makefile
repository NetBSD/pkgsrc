# $NetBSD: Makefile,v 1.3 2012/10/06 14:25:19 asau Exp $
#

DISTNAME=	tegaki-pygtk-0.3.1
PKGREVISION=	2
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Base user interface library for the Tegaki project
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-python>=0.2:../../inputmethod/tegaki-python
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.10:../../x11/py-gtk2

USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
