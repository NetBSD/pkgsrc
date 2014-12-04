# $NetBSD: Makefile,v 1.1 2014/12/04 12:10:04 obache Exp $

DISTNAME=	brise-0.30
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://rimeime.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/rimeime/
COMMENT=	Official Rime Schema repository
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	kyotocabinet-[0-9]*:../../databases/kyotocabinet
DEPENDS+=	librime>=1.0:../../inputmethod/librime

WRKSRC=		${WRKDIR}/brise
USE_LANGUAGES=	# none

USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
