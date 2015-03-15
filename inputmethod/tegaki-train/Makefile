# $NetBSD: Makefile,v 1.7 2015/03/15 18:31:53 hiramatsu Exp $

DISTNAME=	tegaki-train-0.3.1
PKGREVISION=	1
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Train Tegaki with your own handwriting
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-pygtk>=0.2:../../inputmethod/tegaki-pygtk

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.3.1

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
