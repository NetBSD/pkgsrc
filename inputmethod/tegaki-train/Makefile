# $NetBSD: Makefile,v 1.3 2012/10/06 14:25:19 asau Exp $
#

DISTNAME=	tegaki-train-0.3.1
PKGREVISION=	1
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Train Tegaki with your own handwriting
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-pygtk>=0.2:../../inputmethod/tegaki-pygtk

USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
