# $NetBSD: Makefile,v 1.1.1.1 2010/08/07 12:53:49 obache Exp $
#

DISTNAME=	tegaki-train-0.3.1
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Train Tegaki with your own handwriting
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-pygtk>=0.2:../../inputmethod/tegaki-pygtk

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
