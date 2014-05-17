# $NetBSD: Makefile,v 1.50 2014/05/17 16:10:48 wiz Exp $

VERSION_DATE=	2014.04.11.2
DISTNAME=	youtube-dl-${VERSION_DATE}
PKGNAME=	youtube-dl-${VERSION_DATE:S/.//S/.//}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://youtube-dl.org/downloads/${VERSION_DATE}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rg3.github.io/youtube-dl/
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
