# $NetBSD: Makefile,v 1.19 2023/08/14 05:24:41 wiz Exp $

DISTNAME=	tegaki-tools-0.3.1
PKGREVISION=	6
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
