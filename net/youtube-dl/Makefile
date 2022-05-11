# $NetBSD: Makefile,v 1.246 2022/05/11 17:58:35 jklos Exp $

# XXX: VERSION_DATE can contains also an optional part that indicates
# XXX: possible same day revisions. PKGNAME preserves that dotted part as is.
VERSION_DATE=	2021.12.17
DISTNAME=	youtube-dl-${VERSION_DATE}
PKGNAME=	${DISTNAME:S/.//:S/.//}
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	https://youtube-dl.org/downloads/${VERSION_DATE}/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://ytdl-org.github.io/youtube-dl/
COMMENT=	Download videos from youtube.com
LICENSE=	public-domain

USE_LANGUAGES=	# none
EGG_NAME=	youtube_dl-${VERSION_DATE:S/.0/./g}
WRKSRC=		${WRKDIR}/youtube-dl

USE_PKG_RESOURCES=	yes

SUBST_CLASSES+=		pkgmandir
SUBST_STAGE.pkgmandir=	pre-configure
SUBST_FILES.pkgmandir=	setup.py
SUBST_VARS.pkgmandir=	PKGMANDIR

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/bash-completion/completions/youtube-dl.bash-completion \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/youtube-dl

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
