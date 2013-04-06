# $NetBSD: Makefile,v 1.3 2013/04/06 03:45:15 rodent Exp $
#

DISTNAME=	tegaki-zinnia-traditional-chinese-light-0.3
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://www.tegaki.org/releases/0.3/models/
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Zinnia-Traditional-Chinese Tegaki project handwriting model (light)
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	tegaki-zinnia-traditional-chinese-[0-9]*

USE_LANGUAGES=	# none

NO_BUILD=		yes

INSTALLATION_DIRS=	share/tegaki/models/zinnia

INSTALL_MAKE_FLAGS+=	installpath=${DESTDIR}${PREFIX}/share/tegaki/models/zinnia

.include "../../mk/bsd.pkg.mk"
