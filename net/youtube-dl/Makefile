# $NetBSD: Makefile,v 1.43 2013/08/13 20:34:12 tron Exp $

VERSION_DATE=	2013.08.09
DISTNAME=	youtube-dl-${VERSION_DATE}
PKGNAME=	youtube-dl-${VERSION_DATE:S/.//S/.//}
CATEGORIES=	net
MASTER_SITES=	http://youtube-dl.org/downloads/${VERSION_DATE}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rg3.github.com/youtube-dl/
COMMENT=	Download videos from youtube.com
LICENSE=	public-domain

USE_LANGUAGES=			# none
NO_BUILD=			yes
WRKSRC=				${WRKDIR}/youtube-dl
USE_TOOLS+=			gmake

REPLACE_PYTHON=		youtube-dl

MAKE_FLAGS+=		PREFIX=${PREFIX} \
			BASHCOMPDIR=${PREFIX}/share/bash-completion/completions

.include "../../mk/bsd.prefs.mk"

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
