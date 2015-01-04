# $NetBSD: Makefile,v 1.1 2015/01/04 11:05:15 wiz Exp $

DISTNAME=	eyeD3-0.7.5
CATEGORIES=	audio
MASTER_SITES=	http://eyed3.nicfit.net/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://eyed3.nicfit.net/
COMMENT=	Python tool for working with audio files (in particular, mp3)
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.7.5
REPLACE_SH+=		bin/eyeD3

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
