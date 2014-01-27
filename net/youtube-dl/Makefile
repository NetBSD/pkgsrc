# $NetBSD: Makefile,v 1.48 2014/01/27 22:40:27 wiz Exp $

VERSION_DATE=	2014.01.27.2
DISTNAME=	youtube-dl-${VERSION_DATE}
PKGNAME=	youtube-dl-${VERSION_DATE:S/.//S/.//}
CATEGORIES=	net
MASTER_SITES=	http://youtube-dl.org/downloads/${VERSION_DATE}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rg3.github.com/youtube-dl/
COMMENT=	Download videos from youtube.com
LICENSE=	public-domain

USE_LANGUAGES=	# none
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/youtube-dl
USE_TOOLS+=	gmake

REPLACE_PYTHON=	youtube-dl

MAKE_FLAGS+=	PREFIX=${PREFIX} \
		BASHCOMPDIR=${PREFIX}/share/bash-completion/completions

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
