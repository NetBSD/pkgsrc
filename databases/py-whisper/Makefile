# $NetBSD: Makefile,v 1.13 2025/04/14 11:50:23 adam Exp $

DISTNAME=	whisper-1.1.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/whisper/}

MAINTAINER=	riz@NetBSD.org
HOMEPAGE=	https://github.com/graphite-project/whisper
COMMENT=	Fixed-size database, similar in design to RRD
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

post-install:
.for bin in find-corrupt-whisper-files rrd2whisper update-storage-times \
	whisper-auto-resize whisper-auto-update whisper-create \
	whisper-diff whisper-dump whisper-fetch whisper-fill \
	whisper-info whisper-merge whisper-resize \
	whisper-set-aggregation-method whisper-set-xfilesfactor \
	whisper-update
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin}.py ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
