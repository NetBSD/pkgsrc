# $NetBSD: Makefile,v 1.28 2004/07/22 09:16:03 recht Exp $
#

DISTNAME=	python
PKGNAME=	python-${PYVERSSUFFIX}
CATEGORIES=	lang python
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	The "meta-package" for Python

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

# Ensure version of python the user asks for is selected, even
# if it's not yet installed.
_PYTHON_VERSION=${PYTHON_VERSION_DEFAULT}

do-install:
	@${ECHO} "Linking ${PREFIX}/bin/python to ${PYTHONBIN}"
	@${RM} -f ${PREFIX}/bin/python
	@${LN} -s ${PYTHONBIN} ${PREFIX}/bin/python

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
