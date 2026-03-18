# $NetBSD: Makefile,v 1.10 2026/03/18 09:15:25 wiz Exp $

DISTNAME=	yt_dlp_ejs-0.8.0-py3-none-any
PKGNAME=	${DISTNAME:S/_/-/g:C/-py3.*//}
CATEGORIES=	net python
MASTER_SITES=	https://files.pythonhosted.org/packages/py3/y/yt_dlp_ejs/
EXTRACT_SUFX=	.whl

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://pypi.org/project/yt_dlp_ejs/
COMMENT=	External JavaScript for net/yt-dlp supporting many runtimes
LICENSE=	unlicense

DEPENDS+=	yt-dlp-[0-9]*:../../net/yt-dlp

USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS+=	${PYSITELIB}/yt_dlp_ejs/yt/solver

PLIST_SUBST=	PYSITELIB=${PYSITELIB}

do-extract:
	${EXTRACTOR} -f zip ${DISTDIR}/${DISTFILES} -d ${WRKSRC}

do-install:
	${CP} -r ${WRKSRC}/* \
		${DESTDIR}${PREFIX}/${PYSITELIB}

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
