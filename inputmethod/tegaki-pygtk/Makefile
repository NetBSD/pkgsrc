# $NetBSD: Makefile,v 1.1.1.1 2010/08/07 12:51:29 obache Exp $
#

DISTNAME=	tegaki-pygtk-0.3.1
PKGREVISION=	1
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Base user interface library for the Tegaki project
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-python>=0.2:../../inputmethod/tegaki-python
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.10:../../x11/py-gtk2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
