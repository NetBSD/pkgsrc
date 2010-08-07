# $NetBSD: Makefile,v 1.1.1.1 2010/08/07 13:02:19 obache Exp $
#

DISTNAME=	tegaki-zinnia-traditional-chinese-light-0.3
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://www.tegaki.org/releases/0.3/models/
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Tegaki project handwriting model for Zinnia-Traditional-Chinese (light)
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	tegaki-zinnia-traditional-chinese-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

NO_BUILD=		yes

INSTALLATION_DIRS=	share/tegaki/models/zinnia

INSTALL_MAKE_FLAGS+=	installpath=${DESTDIR}${PREFIX}/share/tegaki/models/zinnia

.include "../../mk/bsd.pkg.mk"
