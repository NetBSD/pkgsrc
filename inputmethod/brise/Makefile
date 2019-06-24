# $NetBSD: Makefile,v 1.4 2019/06/24 10:59:40 nia Exp $

DISTNAME=	brise-0.30
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://rimeime.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rime.im/
COMMENT=	Official Rime Schema repository
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	kyotocabinet-[0-9]*:../../databases/kyotocabinet
DEPENDS+=	librime>=1.0:../../inputmethod/librime

WRKSRC=		${WRKDIR}/brise
USE_LANGUAGES=	# none

USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
