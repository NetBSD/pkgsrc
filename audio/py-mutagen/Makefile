# $NetBSD: Makefile,v 1.14 2014/05/09 07:36:54 wiz Exp $

DISTNAME=	mutagen-1.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	http://mutagen.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/mutagen/
COMMENT=	Audio metadata handling for Python
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.22

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
