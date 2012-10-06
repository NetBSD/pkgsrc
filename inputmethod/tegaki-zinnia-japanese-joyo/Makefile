# $NetBSD: Makefile,v 1.2 2012/10/06 14:25:20 asau Exp $
#

DISTNAME=	tegaki-zinnia-japanese-joyo-0.3
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://www.tegaki.org/releases/0.3/models/
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Tegaki project handwriting model for Zinnia-Japanese (joyo)
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

NO_BUILD=		yes

INSTALLATION_DIRS=	share/tegaki/models/zinnia

INSTALL_MAKE_FLAGS+=	installpath=${DESTDIR}${PREFIX}/share/tegaki/models/zinnia

.include "../../mk/bsd.pkg.mk"
