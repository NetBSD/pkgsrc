# $NetBSD: Makefile,v 1.18 2022/06/30 11:18:31 nia Exp $

DISTNAME=	tegaki-tools-0.3.1
PKGREVISION=	5
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Set of command-line tools for Tegaki
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-python>=0.3:../../inputmethod/tegaki-python
DEPENDS+=	tegaki-pygtk>=0.3:../../inputmethod/tegaki-pygtk

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.3.1

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
