# $NetBSD: Makefile,v 1.3 2015/03/15 18:46:55 hiramatsu Exp $
#

DISTNAME=	tegaki-wagomu-simplified-chinese-0.3
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://www.tegaki.org/releases/0.3/models/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Tegaki project handwriting model for Wagomu-Simplified-Chinese(all)
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

NO_BUILD=		yes

INSTALLATION_DIRS=	share/tegaki/models/wagomu

INSTALL_MAKE_FLAGS+=	installpath=${DESTDIR}${PREFIX}/share/tegaki/models/wagomu

.include "../../mk/bsd.pkg.mk"
