# $NetBSD: Makefile,v 1.19 2022/06/30 11:18:31 nia Exp $

DISTNAME=	tegaki-recognize-0.3.1.2
PKGREVISION=	5
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/0.3.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Tegaki project integration in the desktop
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-pygtk>=0.2:../../inputmethod/tegaki-pygtk

USE_LANGUAGES=	# none

REPLACE_PYTHON=	bin/tegaki-recognize
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.3.1.2

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
