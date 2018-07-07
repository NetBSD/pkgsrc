# $NetBSD: Makefile,v 1.6 2018/07/07 04:56:45 minskim Exp $

DISTNAME=	whisper-1.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=w/whisper/}

MAINTAINER=	riz@NetBSD.org
HOMEPAGE=	https://github.com/graphite-project/whisper
COMMENT=	Fixed-size database, similar in design to RRD
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/*.orig

.include "../../mk/bsd.pkg.mk"
