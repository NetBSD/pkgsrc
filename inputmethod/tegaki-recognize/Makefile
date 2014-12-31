# $NetBSD: Makefile,v 1.7 2014/12/31 13:57:28 wiz Exp $

DISTNAME=	tegaki-recognize-0.3.1.2
PKGREVISION=	1
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/0.3.1/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Tegaki project integration in the desktop
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-pygtk>=0.2:../../inputmethod/tegaki-pygtk

USE_LANGUAGES=	# none

REPLACE_PYTHON=	bin/tegaki-recognize
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.3.1.2

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
