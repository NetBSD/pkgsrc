# $NetBSD: Makefile,v 1.115 2017/07/15 16:11:44 adam Exp $

VERSION_DATE=	2017.07.15
DISTNAME=	youtube-dl-${VERSION_DATE}
PKGNAME=	${DISTNAME:S/.//g}
CATEGORIES=	net
MASTER_SITES=	http://youtube-dl.org/downloads/${VERSION_DATE}/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://rg3.github.io/youtube-dl/
COMMENT=	Download videos from youtube.com
LICENSE=	public-domain

USE_LANGUAGES=	# none
EGG_NAME=	youtube_dl-${VERSION_DATE:S/.0/./g}
WRKSRC=		${WRKDIR}/youtube-dl

SUBST_CLASSES+=		pkgmandir
SUBST_STAGE.pkgmandir=	pre-configure
SUBST_FILES.pkgmandir=	setup.py
SUBST_VARS.pkgmandir=	PKGMANDIR

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
