# $NetBSD: Makefile,v 1.2 2013/12/04 16:48:21 drochner Exp $
#

DISTNAME=	mutagen-1.22
PKGNAME=	mutagen-tools-1.22
CATEGORIES=	audio
MASTER_SITES=	http://mutagen.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/mutagen/
COMMENT=	Audio metadata handling for Python
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
PY_NO_EGG=	yes

DEPENDS+= ${PYPKGPREFIX}-mutagen-[0-9]*:../../audio/py-mutagen

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
