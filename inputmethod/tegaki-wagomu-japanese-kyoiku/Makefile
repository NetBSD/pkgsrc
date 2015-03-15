# $NetBSD: Makefile,v 1.3 2015/03/15 17:47:14 hiramatsu Exp $
#

DISTNAME=	tegaki-wagomu-japanese-kyoiku-0.3
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://www.tegaki.org/releases/0.3/models/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Tegaki project handwriting model for Wagomu-Japanese (kyoiku)
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

NO_BUILD=		yes

INSTALLATION_DIRS=	share/tegaki/models/wagomu

INSTALL_MAKE_FLAGS+=	installpath=${DESTDIR}${PREFIX}/share/tegaki/models/wagomu

.include "../../mk/bsd.pkg.mk"
