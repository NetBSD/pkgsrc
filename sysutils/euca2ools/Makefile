# $NetBSD: Makefile,v 1.7 2016/07/09 13:04:06 wiz Exp $

DISTNAME=	euca2ools-2.1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://downloads.eucalyptus.com/software/euca2ools/2.1/source/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.eucalyptus.com/download/euca2ools
COMMENT=	Manage virtual machines like Amazon EC2, Eucalyptus
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-boto>=2.2:../../net/py-boto
DEPENDS+=	${PYPKGPREFIX}-m2crypto>=0.20.2:../../security/py-m2crypto
DEPENDS+=	${PYPKGPREFIX}-xml-[0-9]*:../../textproc/py-xml
DEPENDS+=	help2man-[0-9]*:../../converters/help2man

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-xml, py-m2crypto

#USE_LANGUAGES=	# none

post-build:
	cd ${WRKSRC}; ${SH} generate-manpages.sh

post-install:
	cd ${WRKSRC}; env MANDIR=${DESTDIR}/${PREFIX}/${PKGMANDIR} \
		PREFIX=${PREFIX} ${SH} install-manpages.sh

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
