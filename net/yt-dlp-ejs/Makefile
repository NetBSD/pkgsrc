# $NetBSD: Makefile,v 1.3 2025/11/19 15:43:40 ryoon Exp $

DISTNAME=	yt_dlp_ejs-0.3.1-py3-none-any
PKGNAME=	${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yt_dlp_ejs/}
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
