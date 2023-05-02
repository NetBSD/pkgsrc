# $NetBSD: Makefile,v 1.1 2023/05/02 20:44:26 wiz Exp $

DISTNAME=	omw-1.4
PKGNAME=	nltk_data-omw14-1.4
CATEGORIES=	textproc
DIST_SUBDIR=	${PKGNAME_NOREV}

HOMEPAGE=	https://omwn.org/
COMMENT=	NLTK Data - Open Multilingual Wordnet
#LICENSE=	Please consult the LICENSE files included with the individual Wordnets. Note that all permit redistribution.

USE_LANGUAGES=	# none

TYPE=		corpora

.include "../../meta-pkgs/nltk_data/common.mk"
MASTER_SITES=	https://raw.githubusercontent.com/nltk/nltk_data/gh-pages/packages/corpora/
.include "../../mk/bsd.pkg.mk"
